/**
 *    author:  MaGnsi0
 *    created: 29.11.2022 19:01:38
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u - 1].emplace_back(v - 1, w);
            adj[v - 1].emplace_back(u - 1, w);
        }
        function<vector<int>(int)> bfs = [&](int source) {
            vector<int> d(n, -1);
            queue<int> q;
            d[source] = 0;
            q.push(source);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (auto& [u, w] : adj[v]) {
                    if (d[u] == -1 && u + 1 != y) {
                        d[u] = d[v] ^ w;
                        q.push(u);
                    }
                }
            }
            return d;
        };
        bool ok = false;
        vector<int> dx = bfs(x - 1), dy = bfs(y - 1);
        set<int> sy;
        for (int i = 0; i < n; ++i) {
            if (i + 1 != y) {
                sy.insert(dy[i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i + 1 != y) {
                ok |= sy.count(dx[i]);
            }
        }
        cout << (ok || dx[y - 1] == 0 ? "YES" : "NO") << "\n";
    }
}
