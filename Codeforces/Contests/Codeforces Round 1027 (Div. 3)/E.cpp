/**
 *    author:  MaGnsi0
 *    created: 26.05.2025 18:32:01
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u; cin >> u; u--;
            int v; cin >> v; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int64_t> max_pos(n, 0), max_neg(n, 0);
        function<void(int, int)> dfs = [&](int v, int p) {
            max_pos[v] = max({a[v] - max_neg[p], a[v] - max_pos[p],int64_t(0)});
            max_neg[v] = min({a[v] - max_neg[p], a[v] - max_pos[p],int64_t(0)});
            for (int u : adj[v]) {
                if (u == p) { continue; }
                dfs(u, v);
            }
        };
        dfs(0, 0);
        for (int i = 0; i < n; ++i) {
            cout << max_pos[i] << (i == n - 1 ? "\n" : " ");
        }
    }
}
