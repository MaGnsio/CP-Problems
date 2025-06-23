/**
 *    author:  MaGnsi0
 *    created: 23.06.2025 18:25:02
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> deg(n);
        vector<pair<int, int>> edg;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u; cin >> u; u--;
            int v; cin >> v; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edg.emplace_back(u, v);
            deg[u]++, deg[v]++;
        }
        int V = -1;
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 2) {
                V = i;
                break;
            }
        }
        if (V == -1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        vector<int> dir(n, -1);
        function<void(int, int)> dfs = [&](int v, int p) {
            for (int u : adj[v]) {
                if (u == p) { continue; }
                dir[u] = dir[v] ^ 1;
                dfs(u, v);
            }
        };
        dir[adj[V][0]] = 0; dfs(adj[V][0], V);
        dir[adj[V][1]] = 1; dfs(adj[V][1], V);
        for (auto& [u, v] : edg) {
            if (u == V) { swap(u, v); }
            if (dir[u] == 1) { swap(u, v); }
        }
        for (auto [u, v] : edg) {
            cout << u + 1 << " " << v + 1 << "\n";
        }
    }
}
