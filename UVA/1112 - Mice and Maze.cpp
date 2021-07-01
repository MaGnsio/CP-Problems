/**
 *    author:  MaGnsi0
 *    created: 22/06/2021 04:52:18
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, e, t, m;
        cin >> n >> e >> t >> m;
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[v].push_back({u, w});
        }
        vector<int> d(n + 1, INT_MAX);
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        d[e] = 0;
        q.push({0, e});
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
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            res += (d[i] <= t);
        }
        cout << res << "\n";
        if (T) {
            cout << "\n";
        }
    }
}
