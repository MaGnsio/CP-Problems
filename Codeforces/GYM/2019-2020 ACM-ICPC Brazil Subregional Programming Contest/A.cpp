/**
 *    author:  MaGnsi0
 *    created: 31.10.2023 22:42:59
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

typedef Point<int64_t> P;
bool circleInter(P a ,P b, int64_t r1, int64_t r2) {
    if (a == b) { return true; }
    P vec = b - a;
    double d2 = vec.dist2(), sum = r1 + r2, dif = r1 - r2;
    if (sum * sum < d2 || dif * dif > d2) { return false; }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    int k; cin >> k;
    vector<P> a(k);
    vector<int64_t> r(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i].x >> a[i].y >> r[i];
    }
    vector<vector<int>> adj(k);
    for (int i = 0; i < k; ++i) {
        for (int j = i + 1; j < k; ++j) {
            if (circleInter(a[i], a[j], r[i], r[j])) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int64_t x1 = INT64_MAX, x2 = INT64_MIN;
    int64_t y1 = INT64_MAX, y2 = INT64_MIN;
    vector<bool> visited(k, false);
    function<void(int)> dfs = [&](int v) {
        visited[v] = true;
        x1 = min(x1, a[v].x - r[v]);
        x2 = max(x2, a[v].x + r[v]);
        y1 = min(y1, a[v].y - r[v]);
        y2 = max(y2, a[v].y + r[v]);
        for (int u : adj[v]) {
            if (visited[u]) { continue; }
            dfs(u);
        }
    };
    for (int i = 0; i < k; ++i) {
        if (visited[i]) { continue; }
        x1 = INT64_MAX, x2 = INT64_MIN;
        y1 = INT64_MAX, y2 = INT64_MIN;
        dfs(i);
        if (x1 <= 0 && x2 >= n) {
            cout << "N";
            return 0;
        }
        if (y1 <= 0 && y2 >= m) {
            cout << "N";
            return 0;
        }
        if (x1 <= 0 && y1 <= 0) {
            cout << "N";
            return 0;
        }
        if (x2 >= n && y2 >= m) {
            cout << "N";
            return 0;
        }
    }
    cout << "S";
}
