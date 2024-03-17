/**
 *    author:  MaGnsi0
 *    created: 27.01.2024 18:03:00
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct segment_tree {
    int N;
    T E;
    vector<T> S;
    function<T(T, T)> F;
    segment_tree(int n, T e, function<T(T, T)> f) : N(n), E(e), S(2 * n, e), F(f) {}
    void update(int j, T x) {
        for (S[j += N] = x; j /= 2;) {
            S[j] = F(S[2 * j], S[2 * j + 1]);
        }
    }
    T query(int L, int R) {
        T l = E, r = E;
        for (L += N, R += N; L < R; L /= 2, R /= 2) {
            if (L % 2) {
                l = F(l, S[L++]);
            }
            if (R % 2) {
                r = F(S[--R], r);
            }
        }
        return F(l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    int Q; cin >> Q;
    vector<int64_t> X(m), V(m);
    for (int i = 0; i < m; ++i) {
        cin >> X[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> V[i];
    }
    map<int, int64_t> XV;
    for (int i = 0; i < m; ++i) {
        XV[X[i]] = V[i];
    }
    segment_tree<int64_t> harbours(n + 1, 0, [](int64_t x, int64_t y) { return x + y; });
    segment_tree<int64_t> segments(n + 1, 0, [](int64_t x, int64_t y) { return x + y; });
    function<int64_t(int, int)> sum = [&](int from, int to) {
        if (from > to) { return int64_t(0); }
        int64_t x = 1LL * from * (from - 1) / 2;
        int64_t y = 1LL * to * (to + 1) / 2;
        return y - x;
    };
    function<int64_t(int, int, int, int)> get = [&](int low, int high, int L, int R) {
        if (low > high) { return int64_t(0); }
        int64_t k = high - low + 1;
        int64_t v = XV[L] * (k * R - sum(low, high));
        return v;
    };
    int64_t prevX = XV.begin() -> first;
    for (auto [x, v] : XV) {
        harbours.update(x, 1);
        if (x == prevX) { continue; }
        segments.update(x, get(prevX + 1, x - 1, prevX, x)); 
        prevX = x;
    }
    set<int> h(X.begin(), X.end());
    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            int64_t x; cin >> x;
            int64_t v; cin >> v;
            XV[x] = v;
            auto it = h.lower_bound(x);
            int next_h = *it; it--;
            int prev_h = *it;
            segments.update(x, get(prev_h + 1, x - 1, prev_h, x));
            segments.update(next_h, get(x + 1, next_h - 1, x, next_h));
            harbours.update(x, 1);
            h.insert(x);
        } else {
            int low; cin >> low;
            int high; cin >> high;
            int harbours_count = harbours.query(low, high + 1);
            int64_t ans = 0;
            if (harbours_count == 0) {
                auto it = h.lower_bound(low);
                int R = *it; it--;
                int L = *it;
                ans += get(low, high, L, R);
            } else if (harbours_count == 1) {
                if (low > 1 && high < n) {
                    auto it = h.lower_bound(low);
                    int M = *it; --it;
                    int L = *it; ++it; ++it;
                    int R = *it;
                    ans += get(low, M - 1, L, M);
                    ans += get(M + 1, high, M, R);
                } else if (low == 1) {
                    auto it = h.upper_bound(low);
                    int R = *it;
                    ans += get(low + 1, high, 1, R);
                } else {
                    auto it = h.lower_bound(low); it--;
                    int L = *it;
                    ans += get(low, high - 1, L, n);
                }
            } else {
                auto it1 = h.lower_bound(low);
                int L = *it1; it1--;
                if (low > 1) {
                    int prev_L = *it1;
                    ans += get(low, L - 1, prev_L,  L);
                }
                ans += segments.query(L + 1, high + 1);
                if (high < n) {
                    auto it2 = h.upper_bound(high);
                    int R = *it2; --it2;
                    int prev_R = *it2;
                    ans += get(prev_R + 1, high, prev_R, R);
                }
            }
            cout << ans << "\n";
        }
    }
}
