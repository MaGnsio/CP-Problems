/**
 *    author:  MaGnsi0
 *    created: 14.10.2021 14:31:24
**/
#include <bits/stdc++.h>

using namespace std;

void dijkstra(vector<vector<pair<int, long long>>>& adj, vector<long long>& d, int root) {
    queue<int> q;
    vector<bool> visited((int)d.size(), false);
    d[root] = 0;
    q.push(root);
    visited[root] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& [u, w] : adj[v]) {
            if (visited[u]) {
                continue;
            }
            d[u] = d[v] + w;
            q.push(u);
            visited[u] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<pair<int, long long>>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int u = -1, v = -1;
    {
        vector<long long> d(n, 0);
        dijkstra(adj, d, 0);
        for (int i = 1; i < n; ++i) {
            if (u == -1 || d[i] + a[i] > d[u] + a[u]) {
                u = i;
            }
        }
        d = vector<long long>(n, 0);
        dijkstra(adj, d, u);
        for (int i = 0; i < n; ++i) {
            if (i == u) {
                continue;
            }
            if (v == -1 || d[i] + a[i] > d[v] + a[v]) {
                v = i;
            }
        }
    }
    vector<long long> d_u(n, 0), d_v(n, 0);
    dijkstra(adj, d_u, u);
    dijkstra(adj, d_v, v);
    for (int i = 0; i < n; ++i) {
        if (i != u && i != v) {
            cout << max(d_u[i] + a[u], d_v[i] + a[v]) << "\n";
        } else if (i == u) {
            cout << d_v[i] + a[v] << "\n";
        } else {
            cout << d_u[i] + a[u] << "\n";
        }
    }
}
