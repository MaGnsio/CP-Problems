/**
 *    author:  MaGnsi0
 *    created: 24.10.2024 18:40:24
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
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u; cin >> u; u--;
            int v; cin >> v; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int m; cin >> m;
        vector<vector<pair<int, int>>> Q(n);
        for (int i = 0; i < m; ++i) {
            int v; cin >> v; v--;
            int k; cin >> k;
            Q[v].emplace_back(k, i);
        }
        vector<int> depth(n), farthest(n), ans(m);
        segment_tree<int> b(n, -n, [](int x, int y) { return max(x, y); });
        function<void(int, int)> dfs = [&](int v, int p) {
            depth[v] = (p == -1 ? 0 : depth[p] + 1);
            farthest[v] = 0;
            for (int u : adj[v]) {
                if (u == p) { continue; }
                dfs(u, v);
                farthest[v] = max(farthest[v], farthest[u] + 1);
            }
        };
        function<void(int, int)> solve = [&](int v, int p) {
            multiset<int> s;
            for (auto [k, i] : Q[v]) {
                int min_depth = max(depth[v] - k, 0);
                ans[i] = max(farthest[v], b.query(min_depth, depth[v]) + depth[v]);
            }
            for (int u : adj[v]) {
                if (u == p) { continue; }
                s.insert(farthest[u] + 1);
            }
            for (int u : adj[v]) {
                if (u == p) { continue;}
                auto it = s.find(farthest[u] + 1);
                s.erase(it);
                if (s.empty()) {
                    b.update(depth[v], -depth[v]);
                } else {
                    b.update(depth[v], *s.rbegin() - depth[v]);
                }
                solve(u, v);
                s.insert(farthest[u] + 1);
            }
            b.update(depth[v], -n);
        };
        dfs(0, -1); solve(0, -1);
        for (int i = 0; i < m; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
