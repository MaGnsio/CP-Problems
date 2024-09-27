/**
 *    author:  MaGnsi0
 *    created: 27.09.2024 17:38:38
**/
#include <bits/stdc++.h>

using namespace std;

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
        vector<int> depth(n), max_depth(n); 
        function<void(int, int)> dfs = [&](int v, int p) {
            depth[v] = (v == 0 ? 0 : depth[p] + 1);
            max_depth[v] = depth[v];
            for (int u : adj[v]) {
                if (u == p) { continue; }
                dfs(u, v);
                max_depth[v] = max(max_depth[v], max_depth[u]);
            }
        };
        dfs(0, -1);
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            a[depth[i]]++; b[max_depth[i]]++;
        }
        for (int i = 1; i < n; ++i) {
            a[i] += a[i - 1];
            b[i] += b[i - 1];
        }
        int ans = n;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, n - a[i] + (i ? b[i - 1] : 0));
        }
        cout << ans << "\n";
    }
}
