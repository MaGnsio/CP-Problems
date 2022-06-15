/**
 *    author:  MaGnsi0
 *    created: 20.05.2022 02:38:12
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1][v - 1]++;
        adj[v - 1][u - 1]++;
    }
    int N = (1 << n);
    vector<vector<int64_t>> dp(n, vector<int64_t>(N, -1));
    function<int64_t(int, int, int)> solve = [&](int cur_node, int mask, int start_node) {
        if (dp[cur_node][mask] != -1) {
            return dp[cur_node][mask];
        }
        dp[cur_node][mask] = (__builtin_popcount(mask) > 2 ? adj[start_node][cur_node] : 0);
        for (int v = start_node; v < n; ++v) {
            if (!((mask >> v) & 1)) {
                dp[cur_node][mask] += adj[cur_node][v] * solve(v, mask | (1 << v), start_node);
            }
        }
        return dp[cur_node][mask];
    };
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += solve(i, (1 << i), i) / 2;
    }
    cout << ans;
}
