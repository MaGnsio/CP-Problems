/**
 *    author:  MaGnsi0
 *    created: 30.10.2023 20:03:59
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
    int T; cin >> T;
    while (T--) {
        int n = 1;
        int m; cin >> m;
        vector<int> time(n, 0);
        vector<vector<int>> adj(n);
        vector<vector<pair<int, int>>> add(n);
        for (int i = 1; i <= m; ++i) {
            int t; cin >> t;
            if (t == 1) {
                int v; cin >> v; v--;
                adj[v].push_back(n++);
                time.push_back(i);
                adj.push_back({});
                add.push_back({});
            } else {
                int v; cin >> v; v--;
                int x; cin >> x;
                add[v].emplace_back(i, x);
            }
        }
        vector<int64_t> ans(n);
        segment_tree<int64_t> b(m + 1, 0, [](int64_t x, int64_t y) { return x + y; });
        function<void(int)> dfs = [&](int v) {
            for (auto [t, val] : add[v]) {
                b.update(t, +val);
            }
            ans[v] = b.query(time[v], m + 1);
            for (int u : adj[v]) {
                dfs(u);
            }
            for (auto [t, val] : add[v]) {
                b.update(t, -val);
            }
        };
        dfs(0);
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
