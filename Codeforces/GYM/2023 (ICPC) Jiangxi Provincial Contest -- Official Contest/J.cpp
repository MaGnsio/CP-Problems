/**
 *    author:  MaGnsi0
 *    created: 10.11.2023 22:07:30
**/
#include <bits/stdc++.h>

using namespace std;

struct Line {
    mutable int64_t k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(int64_t x) const { return p < x; }
};
 
struct LineContainer : multiset<Line, less<>> {
    static const int64_t OO = LLONG_MAX;
    int64_t div(int64_t a, int64_t b) {
        return a / b - ((a ^ b) < 0 && a % b);
    }
    bool isect(iterator x, iterator y) {
        if (y == end()) { return x -> p = OO, 0; }
        if (x -> k == y -> k) {
            x -> p = x -> m > y -> m ? OO : -OO;
        } else {
            x -> p = div(y -> m - x -> m, x -> k - y -> k);
        }
        return x -> p >= y -> p;
    }
    void add(int64_t k, int64_t m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) { z = erase(z); }
        if (x != begin() && isect(--x, y)) { isect(x, y = erase(y)); }
        while ((y = x) != begin() && (--x) -> p >= y -> p) {
            isect(x, erase(y));
        }
    }
    int64_t query(int64_t x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    LineContainer L;
    for (int64_t a = 1; a <= n; ++a) {
        int64_t b; cin >> b;
        int64_t M = -2 * a;
        int64_t B = a * a + b;
        L.add(-M, -B);
    }
    int Q; cin >> Q;
    while (Q--) {
        int t; cin >> t;
        if (t == 0) {
            int64_t a; cin >> a;
            int64_t b; cin >> b;
            int64_t M = -2 * a;
            int64_t B = a * a + b;
            L.add(-M, -B);
        } else {
            int64_t x; cin >> x;
            int64_t ans = x * x - L.query(x);
            cout << ans << "\n";
        }
    }
}
