/**
 *    author:  MaGnsi0
 *    created: 09/06/2021 23:56:53
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, s, e;
    cin >> n >> m >> s >> e;
    vector<vector<pair<int, int>>> adj(n + m + 1);
    int f = n + 1;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w < 2) {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        } else {
            adj[u].push_back({f, 1});
            adj[f].push_back({u, 1});
            adj[f].push_back({v, 1});
            adj[v].push_back({f++, 1});
        }
    }
    vector<int> d(n + m + 1, INT_MAX);
    deque<int> q;
    q.push_front(s);
    d[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (auto& [u, w] : adj[v]) {
            if (d[v] + w < d[u]) {
                d[u] = d[v] + w;
                if (w == 1) {
                    q.push_back(u);
                } else {
                    q.push_front(u);
                }
            }
        }
    }
    cout << d[e];
}
