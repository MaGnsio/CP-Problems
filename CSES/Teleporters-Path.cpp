/**
 *    author:  MaGnsi0
 *    created: 08/07/2021 16:20:48
**/
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<int>& out_deg, vector<int>& epath, int v = 1) {
    while (out_deg[v]) {
        int u = adj[v][--out_deg[v]];
        dfs(adj, out_deg, epath, u);
    }
    epath.push_back(v);
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m;
    cin >> n >> m;
    vector<int> in_deg(n + 1, 0), out_deg(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in_deg[v]++, out_deg[u]++;
    }
    if ((out_deg[1] - in_deg[1] != 1) || (in_deg[n] - out_deg[n] != 1)) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for (int i = 2; i < n; ++i) {
        if (in_deg[i] != out_deg[i]) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    vector<int> epath;
    dfs(adj, out_deg, epath);
    if (epath.size() != m + 1) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    reverse(epath.begin(), epath.end());
    for (auto& v : epath) {
        cout << v << " ";
    }
}
