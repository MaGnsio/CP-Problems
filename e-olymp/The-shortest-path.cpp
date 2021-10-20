/**
 *    author:  MaGnsi0
 *    created: 08/06/2021 21:06:07
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, s, e;
    cin >> n >> m >> s >> e;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> d(n + 1, -1), p(n + 1, -1);
    queue<int> q;
    q.push(e);
    d[e] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& u : adj[v]) {
            if (d[u] == -1) {
                q.push(u);
                p[u] = v;
                d[u] = d[v] + 1;
            }
        }
    }
    if (d[s] == -1) {
        cout << d[s];
    } else {
        cout << d[s] << "\n";
        for (int v = s; v != -1; v = p[v]) {
            cout << v << " ";
        }
    }
}
