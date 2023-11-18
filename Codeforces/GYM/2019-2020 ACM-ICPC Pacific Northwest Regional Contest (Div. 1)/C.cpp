/**
 *    author:  MaGnsi0
 *    created: 03.11.2023 17:10:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u; cin >> u; u--;
        int v; cin >> v; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> d(n, n + 1);
    queue<int> q;
    q.push(0);
    d[0] = 0;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int u : adj[v]) {
            if (d[v] + 1 < d[u]) {
                q.push(u);
                d[u] = d[v] + 1;
            }
        }
    }
    cout << d[n - 1] - 1;
}
