/**
 *    author:  MaGnsi0
 *    created: 28.10.2025 18:08:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u; cin >> u; u--;
            int v; cin >> v; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int64_t> s(n), p(n, -1);
        function<void(int, int)> dfs = [&](int v, int p_) {
            s[v] = 1; p[v] = p_;
            for (int u : adj[v]) {
                if (u == p_) { continue; }
                dfs(u, v);
                s[v] += s[u];
            }
        };
        dfs(0, -1);
        int64_t ans = n;
        for (int v = 0; v < n; ++v) {
            ans += (s[v] >= k) * (n - s[v]);
            for (int u : adj[v]) {
                if (u == p[v]) { continue; }
                ans += (n - s[u] >= k) * s[u];
            }
        }
        cout << ans << "\n";
    }
}
