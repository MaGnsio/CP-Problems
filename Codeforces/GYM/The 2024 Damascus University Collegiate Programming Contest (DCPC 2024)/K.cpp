/**
 *    author:  MaGnsi0
 *    created: 19.07.2024 00:34:45
**/
#include <bits/stdc++.h>

using namespace std;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
    typedef Point P;
    T x, y, c;
    explicit Point(T x=0, T y=0, T c=0) : x(x), y(y), c(c) {}
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

typedef Point<int64_t> P;

vector<P> convexHull(vector<P> pts) {
    if ((int)pts.size() <= 1) return pts;
    vector<P> h((int)pts.size() + 1);
    int s = 0, t = 0;
    for (int it = 2; it--; s = --t, reverse(pts.begin(), pts.end())) {
        for (P p : pts) {
            while (t >= s + 2 && h[t - 2].cross(h[t - 1], p) <= 0) { t--; }
            h[t++] = p;
        }
    }
    return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

void reorder_polygon(vector<P>& c) {
    int pos = 0;
    for (int i = 1; i < (int)c.size(); ++i) {
        if ((c[i].y < c[pos].y) || (c[i].y == c[pos].y && c[i].x < c[pos].x)) {
            pos = i;
        }
    }
    rotate(c.begin(), c.begin() + pos, c.end());
}

vector<P> minkowski(vector<P> a, vector<P> b) {
    reorder_polygon(a);
    reorder_polygon(b);
    a.push_back(a[0]);
    a.push_back(a[1]);
    b.push_back(b[0]);
    b.push_back(b[1]);
    int i = 0, j = 0;
    vector<P> result;
    while (i < (int)a.size() - 2 || j < (int)b.size() - 2) {
        result.push_back(a[i] + b[j]);
        int64_t cross = (a[i + 1] - a[i]).cross(b[j + 1] - b[j]);
        if (cross >= 0 && i < a.size() - 2) { ++i; }
        if (cross <= 0 && j < b.size() - 2) { ++j; }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<P> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].x >> a[i].y >> a[i].c;
        }
        sort(a.begin(), a.end());
        int64_t ans = 0;
        for (int bit = 0; bit < 20; ++bit) {
            vector<P> b, c;
            for (P p : a) {
                if (p.c >> bit & 1) {
                    b.push_back(p);
                } else {
                    c.push_back(P(-p.x, -p.y, p.c));
                }
            }
            reverse(c.begin(), c.end());
            b = convexHull(b);
            c = convexHull(c);
            if (b.empty() || c.empty()) { continue; }
            vector<P> minkowski_sum = minkowski(b, c);
            for (P p : minkowski_sum) {
                ans = max(ans, p.dist2());
            }
        }
        cout << ans << "\n";
    }
}
