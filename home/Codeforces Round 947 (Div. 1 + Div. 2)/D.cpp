/**
 *    author:  MaGnsi0
 *    created: 28.05.2024 22:58:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int x; cin >> x; x--;
        int y; cin >> y; y--;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u; cin >> u; u--;
            int v; cin >> v; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        function<vector<int>(int)> bfs = [&](int source) {
            vector<int> d(n, -1);
            queue<int> Q;
            d[source] = 0, Q.push(source);
            while (!Q.empty()) {
                int v = Q.front(); Q.pop();
                for (int u : adj[v]) {
                    if (d[u] != -1) { continue; }
                    d[u] = d[v] + 1, Q.push(u);
                }
            }
            return d;
        };
        vector<vector<int>> a(2);
        a[0] = bfs(x), a[1] = bfs(y);
        int l = a[0][y];
        if (l % 2 == 0) {
            int s = 0;
            for (int i = 0; i < n; ++i) {
                if (a[0][i] == l / 2 && a[1][i] == l / 2) {
                    s = i;
                }
            }
            vector<int> b = bfs(s);
            int ans = (l / 2) + 2 * (n - 1) - *max_element(b.begin(), b.end());
            cout << ans << "\n";
        } else {
            int s = 0;
            for (int i = 0; i < n; ++i) {
                if (a[0][i] == (l - 1) / 2 && a[1][i] == (l + 1) / 2) {
                    s = i;
                }
            }
            vector<int> b = bfs(s);
            int ans = ((l - 1) / 2) + 2 * (n - 1) - *max_element(b.begin(), b.end()) + 1;
            cout << ans << "\n";
        }
    }
}
