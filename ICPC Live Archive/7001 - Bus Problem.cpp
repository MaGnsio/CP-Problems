/**
 *    author:  MaGnsi0
 *    created: 01/07/2021 04:52:52
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, res = 0;
        cin >> n >> m;
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            res += w;
        }
        vector<pair<int, int>> min_edge(n, {-1, INT_MAX});
        vector<bool> visited(n, false);
        set<pair<int, int>> s;
        min_edge[0].second = 0;
        s.insert({0, 0});
        for (int i = 0; i < n; ++i) {
            int v = s.begin() -> second, w_v = s.begin() -> first;
            s.erase(s.begin());
            visited[v] = true;
            res -= w_v;
            for (auto& p : adj[v]) {
                int u = p.first, w = p.second;
                if (!visited[u] && w < min_edge[u].second) {
                    s.erase({min_edge[u].second, u});
                    min_edge[u] = {v, w};
                    s.insert({w, u});
                }
            }
        }
        cout << res << "\n";
    }
}
