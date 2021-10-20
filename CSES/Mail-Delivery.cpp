/**
 *    author:  MaGnsi0
 *    created: 06/07/2021 20:59:35
**/
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<pair<int, int>>>& adj, vector<bool>& visited, vector<int>& epath, vector<int>& idx, vector<int>& deg, int v) {
    while (deg[v]) {
        deg[v]--;
        while (visited[adj[v][idx[v]].second]) {
            idx[v]--;
        }
        visited[adj[v][idx[v]].second] = true;
        int u = adj[v][idx[v]].first;
        deg[u]--;
        dfs(adj, visited, epath, idx, deg, u);
    }
    epath.push_back(v);
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m;
    cin >> n >> m;
    vector<int> deg(n + 1, 0), idx(n + 1, -1);
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        deg[u]++, deg[v]++;
        idx[u]++, idx[v]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (deg[i] & 1) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    vector<bool> visited(m, false);
    vector<int> epath;
    dfs(adj, visited, epath, idx, deg, 1);
    if (epath.size() != m + 1) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for (auto& v : epath) {
        cout << v << " ";
    }
}
