/**
 *    author:  MaGnsi0
 *    created: 08/07/2021 19:43:07
**/
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<pair<int, int>>>& adj, vector<bool>& visited, vector<int>& idx, vector<int>& deg, vector<int>& epath, int v) {
    while (deg[v]) {
        while (visited[adj[v][idx[v]].second]) {
            idx[v]--;
        }
        int u = adj[v][idx[v]].first;
        visited[adj[v][idx[v]].second] = true;
        deg[v]--, deg[u]--;
        dfs(adj, visited, idx, deg, epath, u);
    }
    epath.push_back(v);
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int m;
        cin >> m;
        vector<int> deg(51, 0), idx(51, -1);
        vector<vector<pair<int, int>>> adj(51);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
            deg[u]++, deg[v]++;
            idx[u]++, idx[v]++;
        }
        bool ok = true;
        for (int i = 0; i < 51; ++i) {
            if (deg[i] & 1) {
                ok = false;
                break;
            }
        }
        cout << "Case #" << t << "\n";
        if (!ok) {
            cout << "some beads may be lost\n";
        } else {
            int v;
            for (int i = 1; i < 51; ++i) {
                if (deg[i]) {
                    v = i;
                    break;
                }
            }
            vector<int> epath;
            vector<bool> visited(m, false);
            dfs(adj, visited, idx, deg, epath, v);
            for (int i = 1; i < m + 1; ++i) {
                cout << epath[i - 1] << " " << epath[i] << "\n";
            }
        }
        if (t < T) {
            cout << "\n";
        }
    }
}
