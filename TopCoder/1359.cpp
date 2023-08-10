/**
 *    author:  MaGnsi0
 *    created: 04.07.2023 17:41:41
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

template<class T>
T polygonArea(vector<Point<T>>& v) {
    T a = v.back().cross(v[0]);
    for(int i = 0; i < (int)v.size(); ++i) {
        a += v[i].cross(v[i+1]);
    }
    return abs(a / 2);
}

class Surveyor {
    public:
        int area(string s, vector<int> a) {
            int n = (int)a.size(), x = 0, y = 0;
            vector<Point<int64_t>> p;
            p.emplace_back(x, y);
            for (int i = 0; i < n; ++i) {
                if (s[i] == 'N') { y += a[i]; }
                if (s[i] == 'S') { y -= a[i]; }
                if (s[i] == 'E') { x += a[i]; }
                if (s[i] == 'W') { x -= a[i]; }
                p.emplace_back(x, y);
            }
            return polygonArea(p);
        }
};
