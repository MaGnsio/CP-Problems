/**
 *    author:  MaGnsi0
 *    created: 29/07/2021 18:00:30
**/
#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& adj, vector<int>& dp, int i) {
    if (dp[i] != -1) {
        return dp[i];
    }
    dp[i] = 0;
    for (auto& j : adj[i]) {
        dp[i] = max(dp[i], dfs(adj, dp, j) + 1);
    }
    return dp[i];
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }
    vector<int> dp(n, -1);
    for (int i = 0; i < n; ++i) {
        if (dp[i] == -1) {
            dfs(adj, dp, i);
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res = max(res, dp[i]);
    }
    cout << res;
}
