/**
 *    author:  MaGnsi0
 *    created: 10/09/2021 00:52:20
**/
#include <bits/stdc++.h>
using namespace std;

void dfs(int& n, vector<vector<char>>& adj, vector<bool>& visited, vector<int>& res, int v) {
    visited[v] = true;
    res.push_back(v);
    for (int u = 1; u < n; ++u) {
        if (adj[v][u] == '1' && visited[u] == false) {
            dfs(n, adj, visited, res, u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<vector<char>> adj(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adj[i][j];
        }
    }
    vector<int> res;
    vector<bool> visited(n, false);
    dfs(n, adj, visited, res, 0);
    if (res.size() != n) {
        cout << "impossible";
    } else {
        for (int i = n - 1; i >= 0; --i) {
            cout << res[i] << " ";
        }
    }
}
