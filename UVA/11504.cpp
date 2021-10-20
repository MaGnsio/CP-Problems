/**
 *    author:  MaGnsi0
 *    created: 06/07/2021 19:39:30
**/
#include <bits/stdc++.h>
using namespace std;

void dfs1(vector<vector<int>>& adj, vector<bool>& visited, vector<int>& top_sort, int v) {
    visited[v] = true;
    for (auto& u : adj[v]) {
        if (!visited[u]) {
            dfs1(adj, visited, top_sort, u);
        }
    }
    top_sort.push_back(v);
}

void dfs2(vector<vector<int>>& adj, vector<bool>& visited, int v) {
    visited[v] = true;
    for (auto& u : adj[v]) {
        if (!visited[u]) {
            dfs2(adj, visited, u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, res = 0;
        cin >> n >> m;
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector<int> top_sort;
        vector<bool> visited(n + 1, false);
        for (int v = 1; v <= n; ++v) {
            if (!visited[v]) {
                dfs1(adj, visited, top_sort, v);
            }
        }
        reverse(top_sort.begin(), top_sort.end());
        visited.assign(n + 1, false);
        for (auto& v : top_sort) {
            if (!visited[v]) {
                dfs2(adj, visited, v);
                res++;
            }
        }
        cout << res << "\n";
    }
}
