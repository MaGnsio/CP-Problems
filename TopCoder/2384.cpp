/**
 *    author:  MaGnsi0
 *    created: 02.07.2023 23:38:30
**/
#include <bits/stdc++.h>

using namespace std;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
    // angle to x-axis in interval [-pi, pi]
    double angle() const { return atan2(y, x); }
    P unit() const { return *this/dist(); } // makes dist()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated 'a' radians ccw around the origin
    P rotate(double a) const {
        return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")"; }
};

template<class P> bool onSegment(P s, P e, P p) {
    return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

template<class P> vector<P> segInter(P a, P b, P c, P d) {
    auto oa = c.cross(d, a), ob = c.cross(d, b);
    auto oc = a.cross(b, c), od = a.cross(b, d);
    if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0) {
        return {(a * ob - b * oa) / (ob - oa)};
    }
    set<P> s;
    if (onSegment(c, d, a)) { s.insert(a); }
    if (onSegment(c, d, b)) { s.insert(b); }
    if (onSegment(a, b, c)) { s.insert(c); }
    if (onSegment(a, b, d)) { s.insert(d); }
    return {s.begin(), s.end()};
}

class PointInPolygon {
    public:
        string testPoint(vector<string> vertices, int X, int Y) {
            int n = (int)vertices.size();
            vector<Point<double>> a(n);
            for (int i = 0; i < n; ++i) {
                stringstream sin(vertices[i]);
                double x, y;
                sin >> x >> y;
                a[i] = Point<double>(x, y);
            }
            for (int i = 0; i < n; ++i) {
                if (onSegment(a[i], a[(i + 1) % n], Point<double>(X, Y))) {
                    return "BOUNDARY";
                }
            }
            int cnt = 0;
            Point<double> P0(1e8, 1e7);
            for (int i = 0; i < n; ++i) {
                cnt += !segInter(a[i], a[(i + 1) % n], Point<double>(X, Y), P0).empty();
            }
            return (cnt & 1 ? "INTERIOR" : "EXTERIOR");
        }
};