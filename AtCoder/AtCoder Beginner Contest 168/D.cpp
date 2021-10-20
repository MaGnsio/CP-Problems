/**
 *    author:  MaGnsi0
 *    created: 10/06/2021 15:45:58
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n + 1, false);
    vector<int> par(n + 1, -1);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& u : adj[v]) {
            if (!visited[u]) {
                q.push(u);
                visited[u] = true;
                par[u] = v;
            }
        }
    }
    if (count(par.begin() + 2, par.end(), -1)) {
        cout << "No";
    } else {
        cout << "Yes\n";
        for (int i = 2; i <= n; ++i) {
            cout << par[i] << "\n";
        }
    }
}
