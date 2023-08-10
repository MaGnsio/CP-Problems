/**
 *    author:  MaGnsi0
 *    created: 01.08.2023 15:48:01
**/
#include <bits/stdc++.h>

using namespace std;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y =0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    __int128 cross(P p) const { return __int128(x)*p.y - __int128(y)*p.x; }
    __int128 cross(P a, P b) const { return (a-*this).cross(b-*this); }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
    double angle() const { return atan2(y, x); }
    P unit() const { return *this/dist(); }
    P perp() const { return P(-y, x); }
    P normal() const { return perp().unit(); }
    P rotate(double a) const {
        return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")"; }
};

typedef Point<int64_t> P;

const P O(-1e9, -1e9);

bool onSegment(P s, P e, P p) {
    return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

P segInter(P a, P b, P c, P d) {
    __int128 oa = c.cross(d, a), ob = c.cross(d, b);
    __int128 oc = a.cross(b, c), od = a.cross(b, d);
    if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0) {
        __int128 x = a.x * ob - b.x * oa;
        __int128 y = a.y * ob - b.y * oa;
        if (x % (ob - oa)) { return O; }
        if (y % (ob - oa)) { return O; }
        P p(x / (ob - oa), y / (ob - oa));
        return p;
    }
    if (onSegment(c, d, a)) return a;
    if (onSegment(c, d, b)) return b;
    if (onSegment(a, b, c)) return c;
    if (onSegment(a, b, d)) return d;
    return O;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<P> A(n), B(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i].x >> A[i].y;
        cin >> B[i].x >> B[i].y;
    }
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        if (A[i].x > B[i].x) { swap(A[i], B[i]); }
        if (A[i].x == B[i].x) {
            ans += max(A[i].y, B[i].y) - min(A[i].y, B[i].y) + 1;
        } else if (A[i].y == B[i].y) {
            ans += max(A[i].x, B[i].x) - min(A[i].x, B[i].x) + 1;
        } else {
            int64_t Dx = abs(A[i].x - B[i].x);
            int64_t Dy = abs(A[i].y - B[i].y);
            int64_t g = __gcd(Dy, Dx);
            Dx /= g, Dy /= g;
            ans += (B[i].x - A[i].x) / Dx + 1;
        }
    }
    map<P, set<int>> S;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            P p = segInter(A[i], B[i], A[j], B[j]);
            S[p].insert(i), S[p].insert(j);
        }
    }
    S.erase(O);
    for (auto [_, s] : S) {
        ans -= (int)s.size() - 1;
    }
    cout << ans;
}
