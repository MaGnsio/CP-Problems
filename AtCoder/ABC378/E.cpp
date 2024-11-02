/**
 *    author:  MaGnsi0
 *    created: 02.11.2024 18:08:27
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
        for (S[j += N] += x; j /= 2;) {
            S[j] = F(S[2 * j], S[2 * j + 1]);
        }
    }
    T query(int L, int R) {
        if (L >= R) { return 0; }
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
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; a[i] %= m;
    }
    for (int i = 1; i < n; ++i) {
        a[i] += a[i - 1]; a[i] %= m;
    }
    int64_t ans = 0;
    segment_tree<int64_t> b(m, 0, [](int64_t x, int64_t y) { return x + y; });
    segment_tree<int64_t> c(m, 0, [](int64_t x, int64_t y) { return x + y; });
    c.update(0, 1);
    for (int i = 0; i < n; ++i) {
        ans += c.query(0, a[i]) * a[i] - b.query(0, a[i]);
        ans += c.query(a[i] + 1, m) * a[i] - b.query(a[i] + 1, m) + m * c.query(a[i] + 1, m);
        b.update(a[i], a[i]); c.update(a[i], 1);
    }
    cout << ans;
}
