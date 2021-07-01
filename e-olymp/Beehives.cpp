/**
 *    author:  MaGnsi0
 *    created: 08/06/2021 23:59:46
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin.ignore();
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            vector<int> d(n, -1), p(n, -1);
            queue<int> q;
            q.push(i);
            d[i] = 0;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (auto& u : adj[v]) {
                    if (d[u] != -1 && p[v] != u) {
                        if (d[u] + 1 + d[v] > 2) {
                            ans = min(ans, d[u] + 1 + d[v]);
                        }
                    } else if (d[u] == -1) {
                        q.push(u);
                        d[u] = d[v] + 1;
                        p[u] = v;
                    }
                }
            }
        }
        cout << "Case " << t << ": ";
        if (ans == INT_MAX) {
            cout << "impossible\n";
        } else {
            cout << ans << "\n";
        }
    }
}
