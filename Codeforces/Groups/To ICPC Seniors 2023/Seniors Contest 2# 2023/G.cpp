/**
 *    author:  MaGnsi0
 *    created: 06.02.2023 17:08:34
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("tree.in", "r", stdin);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
    }
    vector<int> top_sort;
    vector<bool> visited(n, false);
    function<void(int)> dfs1 = [&](int v) {
        visited[v] = true;
        for (auto& u : adj[v]) {
            if (!visited[u]) {
                dfs1(u);
            }
        }
        top_sort.push_back(v);
    };
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs1(i);
        }
    }
    reverse(top_sort.begin(), top_sort.end());
    vector<int> size(n), sum(n), cost(n), tree;
    visited = vector<bool>(n, false);
    function<void(int)> dfs2 = [&](int v) {
        visited[v] = true;
        size[v] = 1, sum[v] = b[v], cost[v] = a[v];
        for (auto& u : adj[v]) {
            if (visited[u]) {
                continue;
            }
            dfs2(u);
            size[v] += size[u];
            sum[v] += sum[u];
            cost[v] += cost[u];
        }
        tree.push_back(v);
    };
    for (int i = 0; i < n; ++i) {
        if (!visited[top_sort[i]]) {
            dfs2(top_sort[i]);
        }
    }
    reverse(tree.begin(), tree.end());
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = n - 1; i >= 0; --i) {
        int v = tree[i];
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = dp[i + 1][j];
            if (j >= cost[v]) {
                dp[i][j] = max(dp[i][j], sum[v] + dp[i + size[v]][j - cost[v]]);
            }
        }
    }
    cout << dp[0][k];
}
