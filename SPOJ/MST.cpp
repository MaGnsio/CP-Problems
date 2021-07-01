/**
 *    author:  MaGnsi0
 *    created: 30/06/2021 18:56:40
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m;
    long long res = 0;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<pair<int, int>> min_edge(n + 1, {-1, INT_MAX});
    vector<bool> visited(n + 1, false);
    set<pair<int, int>> s;
    min_edge[1].second = 0;
    s.insert({0, 1});
    for (int i = 0; i < n; ++i) {
        int v = s.begin() -> second, w = s.begin() -> first;
        s.erase(s.begin());
        visited[v] = true;
        res += w;
        for (auto& [u, w] : adj[v]) {
            if (!visited[u] && w < min_edge[u].second) {
                s.erase({min_edge[u].second, u});
                min_edge[u] = {v, w};
                s.insert({w, u});
            }
        }
    }
    cout << res;
}
