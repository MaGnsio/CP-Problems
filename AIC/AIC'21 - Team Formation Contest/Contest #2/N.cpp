/**
 *    author:  MaGnsi0
 *    created: 17/07/2021 13:36:41
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<int>& g1, vector<int>& g2, int v = 0, int c = 0) {
    visited[v] = true;
    if (c) {
        g1.push_back(v);
    } else {
        g2.push_back(v);
    }
    for (auto& u : adj[v]) {
        if (!visited[u]) {
            dfs(adj, visited, g1, g2, u, (c ^ 1));
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& x : a) {
        cin >> x;
    }
    for (auto& x : b) {
        cin >> x;
    }
    vector<int> g1, g2;
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(adj, visited, g1, g2);
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    for (auto& x : g1) {
        x1 += a[x];
        x2 += b[x];
    }
    for (auto& x : g2) {
        y1 += b[x];
        y2 += a[x];
    }
    cout << min(x1 +  y1, x2 + y2);
}
