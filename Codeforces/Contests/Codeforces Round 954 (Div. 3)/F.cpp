/**
 *    author:  MaGnsi0
 *    created: 23.06.2024 19:04:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        vector<vector<int>> adj(n);
        for (int i = 0; i < m; ++i) {
            int u; cin >> u; u--;
            int v; cin >> v; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int dfs_time = 0;
        set<pair<int, int>> bridges;
        vector<bool> visited(n, false);
        vector<int> in(n, 0), low(n, 0);
        function<void(int, int)> dfs = [&](int v, int p) {
            visited[v] = true;
            in[v] = low[v] = dfs_time++;
            for (int u : adj[v]) {
                if (u == p) { continue; }
                if (visited[u]) {
                    low[v] = min(low[v], in[u]);
                } else {
                    dfs(u, v);
                    low[v] = min(low[v], low[u]);
                    if (in[v] < low[u]) {
                        bridges.emplace(u, v);
                    }
                }
            }
        };
        dfs(0, -1);
        vector<int> S(n, 0), P(n, -1);
        visited = vector<bool>(n, false);
        function<void(int, int)> dfs1 = [&](int v, int p) {
            S[v] = 1, P[v] = p;
            visited[v] = true;
            for (int u : adj[v]) {
                if (visited[u]) { continue; }
                dfs1(u, v);
                S[v] += S[u];
            }
        };
        int64_t connected = 1LL * n * (n - 1) / 2, disconnected = 0;
        dfs1(0, -1);
        for (auto [u, v] : bridges) {
            if (P[u] == v) {
                disconnected = max(disconnected, 1LL * S[u] * (n - S[u]));
            } else {
                disconnected = max(disconnected, 1LL * S[v] * (n - S[v]));
            }
        }
        cout << connected - disconnected << "\n";
    }
}
