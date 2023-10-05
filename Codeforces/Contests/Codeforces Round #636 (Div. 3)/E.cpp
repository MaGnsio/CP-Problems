/**
 *    author:  MaGnsi0
 *    created: 25.04.2022 11:17:18
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> b(3);
        for (int i = 0; i < 3; ++i) {
            cin >> b[i];
            b[i]--;
        }
        vector<int64_t> a(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<vector<int>> adj(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }
        vector<vector<int>> d(3, vector<int>(n, 0));
        function<void(int, int)> bfs = [&](int root, int j) {
            vector<bool> visited(n, false);
            queue<int> q;
            d[j][root] = 0;
            visited[root] = true;
            q.push(root);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (auto& u : adj[v]) {
                    if (visited[u]) {
                        continue;
                    }
                    d[j][u] = d[j][v] + 1;
                    visited[u] = true;
                    q.push(u);
                }
            }
        };
        for (int i = 0; i < 3; ++i) {
            bfs(b[i], i);
        }
        vector<int64_t> p(m + 1, 0);
        for (int i = 1; i <= m; ++i) {
            p[i] = a[i - 1] + p[i - 1];
        }
        int64_t ans = INT64_MAX;
        for (int i = 0; i < n; ++i) {
            if (d[0][i] + d[1][i] + d[2][i] <= m) {
                ans = min(ans, p[d[1][i]] + p[d[0][i] + d[1][i] + d[2][i]]);
            }
        }
        cout << ans << "\n";
    }
}
