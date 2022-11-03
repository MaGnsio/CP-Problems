/**
 *    author:  MaGnsi0
 *    created: 08.09.2022 01:42:08
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    vector<vector<int64_t>> dp(n, vector<int64_t>(2, -1));
    function<int64_t(int, int, int)> solve = [&](int v, int c, int p) {
        if (dp[v][c] != -1) {
            return dp[v][c];
        }
        dp[v][c] = 1;
        for (auto& u : adj[v]) {
            if (u == p) {
                continue;
            }
            dp[v][c] *= (solve(u, c ^ 1, v) + (c ? solve(u, c, v) : 0));
            dp[v][c] %= MOD;
        }
        return dp[v][c];
    };
    cout << (solve(0, 0, -1) + solve(0, 1, -1)) % MOD;
}
