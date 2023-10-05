/**
 *    author:  MaGnsi0
 *    created: 29.08.2023 15:05:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, Q;
        cin >> n >> Q;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }
        while (Q--) {
            int k, m;
            cin >> k >> m;
            vector<int> sum(n), depth(n);
            for (int i = 0; i < m; ++i) {
                int u; cin >> u;
                sum[u - 1] = 1;
            }
            function<void(int, int)> dfs = [&](int v, int p) {
                for (int u : adj[v]) {
                    if (u == p) { continue; }
                    depth[u] = depth[v] + 1;
                    dfs(u, v);
                    sum[v] = sum[v] + sum[u];
                }
            };
            dfs(0, -1);
            int ans = 0, max_depth = 0;
            for (int i = 0; i < n; ++i) {
                if (sum[i] >= k) {
                    max_depth = max(max_depth, depth[i]);
                }
            }
            for (int i = 0; i < n; ++i) {
                ans += sum[i] >= k && depth[i] == max_depth;
            }
            cout << ans << "\n";
        }
    }
}
