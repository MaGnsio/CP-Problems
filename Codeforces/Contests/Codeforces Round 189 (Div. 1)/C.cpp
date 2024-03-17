/**
 *    author:  MaGnsi0
 *    created: 31.12.2023 17:42:39
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = INT64_MAX;

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
    vector<int64_t> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    LineContainer L;
    vector<int64_t> dp(n, OO);
    dp[n - 1] = 0; L.add(-a[n - 1], -dp[n - 1]);
    for (int i = n - 2; i >= 0; --i) {
        dp[i] = -L.query(b[i]);
        L.add(-a[i], -dp[i]);
    }
    cout << dp[0];
}
