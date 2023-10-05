/**
 *    author:  MaGnsi0
 *    created: 18.07.2022 23:19:23
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int64_t>> adj(n), pre(n), suf(n);
    for (int u = 1, v; u < n; ++u) {
        cin >> v;
        adj[v - 1].push_back(u);
    }
    vector<int64_t> dp(n, -1);
    function<int64_t(int)> solve = [&](int v) {
        dp[v] = 1;
        for (auto& u : adj[v]) {
            dp[v] *= (solve(u) + 1);
            dp[v] %= MOD;
        }
        int m = (int)adj[v].size();
        if (!m) {
            return dp[v];
        }
        pre[v] = vector<int64_t>(m, 1);
        pre[v][0] = dp[adj[v][0]] + 1;
        for (int i = 1; i < m; ++i) {
            pre[v][i] = pre[v][i - 1];
            pre[v][i] *= (dp[adj[v][i]] + 1);
            pre[v][i] %= MOD;
        }
        suf[v] = vector<int64_t>(m, 1);
        suf[v][m - 1] = dp[adj[v][m - 1]] + 1;
        for (int i = m - 2; i >= 0; --i) {
            suf[v][i] = suf[v][i + 1];
            suf[v][i] *= (dp[adj[v][i]] + 1);
            suf[v][i] %= MOD;
        }
        return dp[v];
    };
    solve(0);
    vector<int64_t> ans(n);
    function<void(int, int)> dfs = [&](int v, int p) {
        ans[v] = dp[v];
        int m = (int)adj[v].size();
        for (int i = 0; i < m; ++i) {
            int64_t u = adj[v][i], old_v = dp[v], old_u = dp[u];
            dp[v] = (i ? pre[v][i - 1] : 1);
            dp[v] *= (i + 1 < m ? suf[v][i + 1] : 1);
            dp[v] %= MOD;
            dp[v] *= (p != -1 ? dp[p] + 1 : 1);
            dp[v] %= MOD;
            dp[u] *= (1 + dp[v]);
            dp[u] %= MOD;
            dfs(u, v);
            dp[v] = old_v;
            dp[u] = old_u;
        }
    };
    dfs(0, -1);
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
}
