/**
 *    author:  MaGnsi0
 *    created: 13.10.2021 16:27:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> adj(n);
        vector<int> deg(n, 0);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++, deg[v]++;
        }
        vector<int> d(n, 0);
        vector<bool> visited(n, false);
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        for (int i = 0; i < n; ++i) {
            if (deg[i] <= 1) {
                q.push({0, i});
                visited[i] = true;
            }
        }
        while (!q.empty()) {
            int v = q.top().second;
            q.pop();
            for (auto& u : adj[v]) {
                if (visited[u]) {
                    continue;
                }
                deg[u]--;
                if (deg[u] <= 1) {
                    d[u] = d[v] + 1;
                    q.push({d[u], u});
                    visited[u] = true;
                }
            }
        }
        int res = n;
        for (int i = 0; i < n; ++i) {
            res -= (d[i] < k);
        }
        cout << res << "\n";
    }
}
