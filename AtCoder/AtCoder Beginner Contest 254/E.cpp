/**
 *    author:  MaGnsi0
 *    created: 11.06.2022 06:15:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> ans(n + 1, vector<int>(4));
    function<void(int, int)> bfs = [&](int x, int y) {
        set<int> visited;
        queue<pair<int, int>> q;
        q.push(make_pair(x, 0));
        visited.insert(x);
        while (!q.empty()) {
            int v = q.front().first, d = q.front().second;
            ans[x][y] += v;
            q.pop();
            if (d == y) {
                continue;
            }
            for (auto& u : adj[v]) {
                if (visited.count(u)) {
                    continue;
                }
                q.push(make_pair(u, d + 1));
                visited.insert(u);
            }
        }
    };
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 3; ++j) {
            bfs(i, j);
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int v, k;
        cin >> v >> k;
        cout << ans[v][k] << "\n";
    }
}
