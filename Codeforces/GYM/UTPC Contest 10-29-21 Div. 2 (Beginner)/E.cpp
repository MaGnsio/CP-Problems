/**
 *    author:  MaGnsi0
 *    created: 21.11.2021 15:54:14
**/
#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>& adj, int& x, int& maxd, int v = 0, int curd = 0, int par = -1) {
    if (curd > maxd) {
        x = v;
        maxd = curd;
    }
    for (auto& u : adj[v]) {
        if (u == par) {
            continue;
        }
        dfs(adj, x, maxd, u, curd + 1, v);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adj1(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }
    int x1 = 0, x2 = 0, maxd1;
    maxd1 = 0;
    dfs(adj1, x1, maxd1);
    maxd1 = 0;
    dfs(adj1, x2, maxd1, x1);
    int m;
    cin >> m;
    vector<vector<int>> adj2(m);
    for (int i = 0; i < m - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }
    int x3 = 0, x4 = 0, maxd2;
    maxd2 = 0;
    dfs(adj2, x3, maxd2);
    maxd2 = 0;
    dfs(adj2, x4, maxd2, x3);
    cout << maxd1 + maxd2 + 2;
}
