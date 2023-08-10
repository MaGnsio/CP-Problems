/**
 *    author:  MaGnsi0
 *    created: 04.07.2023 19:04:55
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

int orientation(Point<double> a, Point<double> b, Point<double> c) {
    double v = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    if (v < 0) { return -1; } // clockwise
    if (v > 0) { return +1; } // counter-clockwise
    return 0;
}

int N, M;
const int Nax = 45;
int64_t dp[Nax][Nax][Nax][Nax];
bool visited[Nax][Nax][Nax][Nax];
vector<Point<int64_t>> a;

typedef Point<int64_t> P;
vector<P> convexHull(vector<P> pts) {
    if (pts.size() <= 1) return pts;
    sort(pts.begin(), pts.end());
    vector<P> h(pts.size()+1);
    int s = 0, t = 0;
    for (int it = 2; it--; s = --t, reverse(pts.begin(), pts.end()))
        for (P p : pts) {
            while (t >= s + 2 && h[t-2].cross(h[t-1], p) <= 0) t--;
            h[t++] = p;
        }
    return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

int64_t solve(int j, int first, int last, int remaining) {
    if (remaining == 0) { return a[last].cross(a[first]); }
    if (j == N) { 
        return (first != 0) * a[last].cross(a[first]);
    }
    int64_t& ans = dp[j][first][last][remaining];
    if (visited[j][first][last][remaining]) { return ans; }
    visited[j][first][last][remaining] = true;
    ans = (first != 0) * a[last].cross(a[first]);
    ans = max(ans, solve(j + 1, first, last, remaining));
    ans = max(ans, solve(j + 1, (first == 0 ? j : first), j, remaining - 1) + (last == 0 ? 0 : a[last].cross(a[j])));
    return ans;
}

class ElectronicScarecrows {
    public:
        double largestArea(vector<int> x, vector<int> y, int m) {
            memset(visited, 0, sizeof visited);
            N = (int)x.size(), M = m;
            a.resize(N);
            for (int i = 0; i < N; ++i) {
                a[i] = Point<int64_t>(x[i], y[i]);
            }
            a = convexHull(a);
            a.insert(a.begin(), Point<int64_t>(0, 0));
            N = (int)a.size();
            double ans = 1.0 * solve(1, 0, 0, min(M, N - 1)) / 2;
            return ans;
        }
};
