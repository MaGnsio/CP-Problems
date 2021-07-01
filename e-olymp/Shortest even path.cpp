/**
 *    author:  MaGnsi0
 *    created: 10/06/2021 00:11:26
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, s, e;
    cin >> n >> m >> s >> e;
    vector<vector<int>> adj(2 * n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v + n);
        adj[v + n].push_back(u);
        adj[u + n].push_back(v);
        adj[v].push_back(u + n);
    }
    vector<int> d(2 * n + 1, INT_MAX);
    queue<int> q;
    q.push(s);
    d[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& u : adj[v]) {
            if (d[u] == INT_MAX) {
                q.push(u);
                d[u] = d[v] + 1;
            }
        }
    }
    cout << (d[e] == INT_MAX ? -1 : d[e]);
}
