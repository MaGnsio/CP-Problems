/**
 *    author:  MaGnsi0
 *    created: 17/06/2021 18:36:52
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, s, e;
        cin >> n >> m >> s >> e;
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<int> d(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        d[s] = 0;
        q.push({0, s});
        while (!q.empty()) {
            int v = q.top().second, d_v = q.top().first;
            q.pop();
            if (d[v] != d_v) {
                continue;
            }
            for (auto& [u, w] : adj[v]) {
                if (d[v] + w < d[u]) {
                    d[u] = d[v] + w;
                    q.push({d[u], u});
                }
            }
        }
        if (d[e] == INT_MAX) {
            cout << "NONE\n";
        } else {
            cout << d[e] << "\n";
        }
    }
}
