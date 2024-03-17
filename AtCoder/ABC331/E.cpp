/**
 *    author:  MaGnsi0
 *    created: 02.12.2023 14:14:52
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
    int k; cin >> k;
    vector<int64_t> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    vector<vector<int>> bad(n);
    for (int i = 0; i < k; ++i) {
        int u; cin >> u; u--;
        int v; cin >> v; v--;
        bad[u].push_back(v);
    }
    int64_t ans = 0;
    segment_tree<int64_t> c(m, 0, [](int64_t x, int64_t y) { return max(x, y); });
    for (int i = 0; i < m; ++i) {
        c.update(i, b[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j : bad[i]) {
            c.update(j, 0);
        }
        int64_t x = c.query(0, m);
        if (x) {
            ans = max(ans, a[i] + x);
        }
        for (int j : bad[i]) {
            c.update(j, b[j]);
        }
    }
    cout << ans;
}
