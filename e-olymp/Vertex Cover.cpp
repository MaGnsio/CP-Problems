/**
 *    author:  MaGnsi0
 *    created: 07/06/2021 01:46:58
**/
#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& adj, int& vc, int v, int par = -1) {
    bool is_cover = false;
    for (auto& u : adj[v]) {
        if (u != par) {
            is_cover |= dfs(adj, vc, u, v);
        }
    }
    vc += is_cover;
    return !is_cover;
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, vc = 0;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(adj, vc, 1);
    cout << vc;
}
