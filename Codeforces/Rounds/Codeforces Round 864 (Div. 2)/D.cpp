/**
 *    author:  MaGnsi0
 *    created: 08.04.2023 18:11:31
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].emplace_back(v - 1);
        adj[v - 1].emplace_back(u - 1);
    }
    vector<int64_t> size(n, 1), parent(n, -1), importance(n, 0);
    vector<set<pair<int, int>>> weight(n);
    function<void(int)> dfs = [&](int v) {
        importance[v] = a[v];
        for (auto& u : adj[v]) {
            if (u == parent[v]) { continue; }
            parent[u] = v;
            dfs(u);
            size[v] += size[u];
            importance[v] += importance[u];
            weight[v].emplace(-size[u], u);
        }
    };
    dfs(0);
    for (int i = 0; i < m; ++i) {
        int t, u;
        cin >> t >> u; u--;
        if (t == 1) {
            cout << importance[u] << "\n";
        } else {
            auto it = weight[u].begin();
            if (it == weight[u].end()) { continue; }
            int v = it -> second, p = parent[u];
            weight[p].erase(make_pair(-size[u], u));
            weight[u].erase(make_pair(-size[v], v));
            {
                int64_t x = size[p], y = size[u], z = size[v];
                size[p] = x, size[u] = y - z, size[v] = y;
            }
            {
                int64_t x = importance[p], y = importance[u], z = importance[v];
                importance[p] = x, importance[u] = y - z, importance[v] = y;
            }
            {
                int64_t x = parent[p], y = parent[u], z = parent[v];
                parent[p] = x, parent[u] = v, parent[v] = p;
            }
            weight[p].insert(make_pair(-size[v], v));
            weight[v].insert(make_pair(-size[u], u));
        }
    }
}
