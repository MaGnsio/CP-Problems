/**
 *    author:  MaGnsi0
 *    created: 11.12.2021 13:52:33
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    for (int i = 0; i < n; ++i) {
        if ((int)adj[i].size() > 2) {
            cout << "No";
            return 0;
        }
    }
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);
    function<bool(int, int)> dfs = [&](int v, int p) {
        visited[v] = true;
        for (auto& u : adj[v]) {
            if (u == p) {
                continue;
            }
            if (visited[u]) {
                return true;
            }
            parent[u] = v;
            if (dfs(u, v)) {
                return true;
            }
        }
        return false;
    };
    for (int i = 0; i < n; ++i) {
        if (!visited[i] && dfs(i, parent[i])) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}
