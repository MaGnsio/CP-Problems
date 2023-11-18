/**
 *    author:  MaGnsi0
 *    created: 24.10.2023 07:09:42
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int v = 1; v < n; ++v) {
        int u; cin >> u; u--;
        adj[u].push_back(v);
    }
    vector<vector<int64_t>> ans(n, vector<int64_t>(2, 0));
    function<void(int)> solve = [&](int v) {
        if ((int)adj[v].empty()) {
            ans[v][0] = ans[v][1] = 1;
            return;
        }
        for (int u : adj[v]) {
            solve(u);
        }
        int m = (int)adj[v].size();
        vector<int64_t> P(m, 1), S(m, 1);
        P[0] = ans[adj[v][0]][0];
        for (int i = 1; i < m; ++i) {
            int u = adj[v][i];
            P[i] = P[i - 1] * ans[u][0] % MOD;
        }
        S[m - 1] = ans[adj[v][m - 1]][0];
        for (int i = m - 2; i >= 0; --i) {
            int u = adj[v][i];
            S[i] = S[i + 1] * ans[u][0] % MOD;
        }
        ans[v][0] = P[m - 1];
        for (int i = 0; i < m; ++i) {
            int u = adj[v][i];
            int64_t x = (i ? P[i - 1] : 1);
            int64_t y = (i + 1 < m ? S[i + 1] : 1);
            ans[v][0] += x * ans[u][1] % MOD * y % MOD;
            ans[v][0] %= MOD;
            ans[v][1] += x * ans[u][1] % MOD * y % MOD;
            ans[v][1] %= MOD;
        }
    };
    solve(0);
    cout << ans[0][0];
}
