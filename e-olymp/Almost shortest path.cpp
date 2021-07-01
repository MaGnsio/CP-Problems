/**
 *    author:  MaGnsi0
 *    created: 10/06/2021 01:23:22
**/
#include <bits/stdc++.h>
using namespace std;

void bfs(int& n, vector<vector<int>>& adj, vector<int>& d, int& s, int& e) {
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
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, s, e;
    cin >> n >> m >> s >> e;
    vector<vector<int>> adj(n + 1);
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }
    vector<int> ds(n + 1, INT_MAX), de(n + 1, INT_MAX);
    set<pair<int, int>> forbidden;
    bfs(n, adj, ds, s, e);
    bfs(n, adj, de, e, s);
    for (auto& [u, v] : edges) {
        if (ds[u] + 1 + de[v] == ds[e] || de[u] + 1 + ds[v] == ds[e]) {
            forbidden.insert({min(u, v), max(u, v)});
        }
    }
    vector<int> d(n + 1, INT_MAX);
    queue<int> q;
    q.push(s);
    d[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& u : adj[v]) {
            if (d[u] != INT_MAX) {
                continue;
            }
            if (forbidden.count({min(u, v), max(u, v)})) {
                continue;
            }
            q.push(u);
            d[u] = d[v] + 1;
        }
    }
    cout << (d[e] == INT_MAX ? -1 : d[e]);
}
