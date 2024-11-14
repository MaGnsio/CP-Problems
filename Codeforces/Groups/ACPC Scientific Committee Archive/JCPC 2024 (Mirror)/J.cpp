/**
 *    author:  MaGnsi0
 *    created: 14.11.2024 18:11:49
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e17;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<vector<pair<int, int64_t>>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u; cin >> u; u--;
            int v; cin >> v; v--;
            int64_t w; cin >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        vector<int64_t> sz(n), sum(n), ans(n, -1);
        function<void(int, int)> dfs = [&](int v, int p) {
            sz[v] = 1, sum[v] = 0;
            for (auto [u, w] : adj[v]) {
                if (u == p) { continue; }
                dfs(u, v);
                sz[v] += sz[u]; sum[v] += sum[u] + w;
            }
        };
        function<int64_t(int, int)> solve = [&](int v, int p) {
            if (ans[v] != -1) { return ans[v]; }
            ans[v] = 0;
            int m = (int)adj[v].size() - (v != 0);
            if (m == 0) { return ans[v]; }
            vector<int64_t> mask_sum(1 << m);
            vector<pair<int, int64_t>> C;
            for (auto [u, w] : adj[v]) {
                if (u == p) { continue; }
                C.emplace_back(u, w);
            }
            for (int mask = 0; mask < (1 << m); ++mask) {
                for (int j = 0; j < m; ++j) {
                    if (mask >> j & 1) {
                        auto [u, w] = C[j];
                        mask_sum[mask] += sum[u] + w;
                    }
                }
            }
            vector<int64_t> dp(1 << m, -1);
            function<int64_t(int)> F = [&](int mask) {
                if (mask + 1 == (1 << m)) { return int64_t(0); }
                if (dp[mask] != -1) { return dp[mask]; }
                dp[mask] = OO;
                for (int j = 0; j < m; ++j) {
                    if (mask >> j & 1) { continue; }
                    auto [u, w] = C[j];
                    dp[mask] = min(dp[mask], sz[u] * (2 * mask_sum[mask] + w) + solve(u, v) + F(mask | (1 << j)));
                }
                return dp[mask];
            };
            return ans[v] = F(0);
        };
        dfs(0, -1);
        for (int v = 0; v < n; ++v) {
            sort(adj[v].begin(), adj[v].end(), [&](auto x, auto y) {
                return x.second < y.second;
            });
        }
        long double e = 1.0 * solve(0, -1) / n;
        cout << fixed << setprecision(10) << e << "\n";
    }
}
