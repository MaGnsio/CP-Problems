/**
 *    author:  MaGnsi0
 *    created: 09/06/2021 00:48:50
**/
#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& adj, vector<int>& d, int& s) {
    queue<int> q;
    q.push(s);
    d[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& u : adj[v]) {
            if (d[u] == -1) {
                q.push(u);
                d[u] = d[v] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, s, t, ans = 0;
    cin >> n >> m >> s >> t;
    set<pair<int, int>> edges;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.insert({min(u, v), max(u, v)});
    }
    vector<int> ds(n + 1, -1), dt(n + 1, -1);
    bfs(adj, ds, s);
    bfs(adj, dt, t);
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (edges.count({i, j})) {
                continue;
            }
            if (ds[i] + 1 + dt[j] >= ds[t] && dt[i] + 1 + ds[j] >= ds[t]) {
                ans++;
            }
        }
    }
    cout << ans;
}
