/**
 *    author:  MaGnsi0
 *    created: 04.07.2023 21:24:05
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
    int64_t dist() const { return sqrt((int64_t)dist2()); }
    // angle to x-axis in interval [-pi, pi]
    int64_t angle() const { return atan2(y, x); }
    P unit() const { return *this/dist(); } // makes dist()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated 'a' radians ccw around the origin
    P rotate(int64_t a) const {
        return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")"; }
};

bool collinear(Point<int64_t> P1, Point<int64_t> P2, Point<int64_t> P3) {
    int64_t x1 = P1.x, x2 = P2.x, x3 = P3.x;
    int64_t y1 = P1.y, y2 = P2.y, y3 = P3.y;
    int64_t a = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
    return a == 0;
}

class Symmetry {
    public:
        int countLines(vector<string> points) {
            int n = (int)points.size();
            vector<Point<int64_t>> a;
            for (int i = 0; i < n; ++i) {
                int x, y;
                stringstream sin(points[i]);
                while (sin >> x >> y) {
                    a.push_back(Point<int64_t>(x, y));
                }
            }
            n = (int)a.size();
            map<tuple<int64_t, int64_t, int64_t>, int> mp;
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    int64_t A = 2 * (a[j].y - a[i].y);
                    int64_t B = -2 * (a[j].x - a[i].x);
                    int64_t C = (a[j].x * a[j].x - a[i].x * a[i].x) + (a[j].y * a[j].y - a[i].y * a[i].y);
                    int64_t G = __gcd(__gcd(A, B), C);
                    A /= G, B /= G, C /= G;
                    mp[{A, B, C}] += 2;
                }
            }
            int ans = 0;
            for (auto [p, cnt] : mp) {
                int64_t A = get<0>(p);
                int64_t B = get<1>(p);
                int64_t C = get<2>(p);
                for (int i = 0; i < n; ++i) {
                    cnt += (A * a[i].y == B * a[i].x + C);
                }
                ans += cnt == n;
            }
            bool all_collinear = true;
            for (int i = 0; i < n; ++i) {
                all_collinear = all_collinear && collinear(a[0], a[1], a[i]);
            }
            return ans + all_collinear;
        }
};
