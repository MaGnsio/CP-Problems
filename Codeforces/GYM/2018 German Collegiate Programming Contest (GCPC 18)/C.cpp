/**
 *    author:  MaGnsi0
 *    created: 17/09/2021 19:42:18
**/
#include <bits/stdc++.h>
using namespace std;

int dijkstra(int n, vector<vector<pair<int, int>>> adj, int i) {
    vector<int> d(n, 0);
    priority_queue<pair<int, int>> q;
    d[i] = 0;
    q.push({0, i});
    while (!q.empty()) {
        int v = q.top().second, d_v = q.top().first;
        q.pop();
        if (d_v != d[v]) { //skip old versions that has already been handled
            continue;
        }
        for (auto& [u, w] : adj[v]) {
            if (d[v] + w > d[u]) {
                d[u] = d[v] + w;
                q.push({d[u], u});
            }
        }
    }
    return *max_element(d.begin(), d.end());
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m;
    cin >> n >> m;
    vector<int> in_deg(n, 0);
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        in_deg[v]++;
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (in_deg[i] == 0) {
            res = max(res, dijkstra(n, adj, i));
        }   
    }
    cout << res;
}
