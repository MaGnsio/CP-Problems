/**
 *    author:  MaGnsi0
 *    created: 06.03.2023 15:53:26
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
    long double dist() const { return sqrt((long double)dist2()); }
    // angle to x-axis in interval [-pi, pi]
    long double angle() const { return atan2(y, x); }
    P unit() const { return *this/dist(); } // makes dist()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated 'a' radians ccw around the origin
    P rotate(long double a) const {
        return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")"; }
};

int x, y, r;

Point<long double> transform(Point<long double> p) {
    long double x1 = x, y1 = y;
    long double x2 = p.x, y2 = p.y;
    long double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    long double l1 = r * r / d;
    long double l2 = d - l1;
    long double x3 = (x1 * l2 + x2 * l1) / (d);
    long double y3 = (y1 * l2 + y2 * l1) / (d);
    return Point<long double>(x3, y3);
}

int  main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> x >> y >> r;
    int n;
    cin >> n;
    vector<Point<long double>> v;
    for(int i = 0; i < n; i++){
        int x1, y1;
        cin >> x1 >> y1;
        x1 -= x; 
        y1 -= y;
        v.push_back(Point<long double>(x1, y1));
    }
    x = y = 0;
    long double total_length = 0;
    for (int i = 0; i < n; ++i) {
        Point<long double> cur = v[i], nxt = v[(i + 1) % n];
        total_length += Point<long double>(cur.x - nxt.x, cur.y - nxt.y).dist();
    }
    long double ans = 0;
    vector<Point<long double>> vp;
    for(int i = 0; i < n; i++){
        Point<long double> cur = v[i], nxt = v[(i + 1) % n];
        long double d = Point<long double>(cur.x - nxt.x, cur.y - nxt.y).dist();
        long double unit = total_length / 5000000;
        int steps = ceil(d / unit);
        long double l1 = 0, l2 = d;
        for(int j = 0; j < steps; j++){
            long double md_x = (cur.x * l2 + nxt.x * l1) / d;
            long double md_y = (cur.y * l2 + nxt.y * l1) / d;
            l1 += unit, l2 -= unit;
            Point<long double> p = transform(Point(md_x, md_y));
            if (vp.size() == 0) {
                vp.push_back(p);
            } else if (vp.size() == 1) {
                ans += vp[0].cross(p);
                vp.push_back(p);
            } else {
                ans += vp.back().cross(p);
                vp.back() = p;
            }
        }
    }
    ans += vp[1].cross(vp[0]);
    cout<< fixed << setprecision(15) << fabs(0.5 * ans);
}
