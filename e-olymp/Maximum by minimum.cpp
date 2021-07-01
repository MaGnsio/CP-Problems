/**
 *    author:  MaGnsi0
 *    created: 08/06/2021 18:48:20
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
    }
    vector<bool> visited(n + 1, false);
    vector<int> d(n + 1, 0);
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& u : adj[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
            }
        }
    }
    cout << *max_element(d.begin() + 1, d.end());
}
