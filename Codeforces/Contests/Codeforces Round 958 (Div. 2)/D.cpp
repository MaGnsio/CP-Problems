/**
 *    author:  MaGnsi0
 *    created: 15.07.2024 18:03:02
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t M = 21, OO = 1e18;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int>> adj(n);
        for (int i  = 0; i < n - 1; ++i) {
            int u; cin >> u; u--;
            int v; cin >> v; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int64_t>> dp(n, vector<int64_t>(M, OO));
        vector<vector<int64_t>> sum(n, vector<int64_t>(M, -1));
        function<int64_t(int, int, int)> solve = [&](int v, int p, int allowed) {
            for (int i = 1; i < M; ++i) {
                if (allowed == i) { continue; }
                if (sum[v][i] == -1) {
                    sum[v][i] = 0;
                    for (int u : adj[v]) {
                        if (u == p) { continue; }
                        sum[v][i] += solve(u, v, i);
                    }
                }
                dp[v][allowed] = min(dp[v][allowed], sum[v][i] + a[v] * i);
            }
            return dp[v][allowed];
        };
        cout << solve(0, -1, 0) << "\n";
    }

}
