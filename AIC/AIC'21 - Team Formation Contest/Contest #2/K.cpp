/**
 *    author:  MaGnsi0
 *    created: 17/07/2021 13:36:38
**/
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<int>& ans, int v, int p) {
    ans[v] = p;
    for (auto& u : adj[v]) {
        if (u != p) {
            dfs(adj, visited, ans, u, v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, r1, r2;
    cin >> n >> r1 >> r2;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (i == r1) {
            continue;
        }
        int x;
        cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    vector<int> ans(n + 1, -1);
    vector<bool> visited(n + 1, false);
    dfs(adj, visited, ans, r2, -1);
    for (auto& x : ans) {
        if (x == -1) {
            continue;
        }
        cout << x << " ";
    }
}
