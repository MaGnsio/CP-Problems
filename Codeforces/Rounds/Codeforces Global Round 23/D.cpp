/**
 *    author:  MaGnsi0
 *    created: 30.10.2022 21:53:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> p(n), s(n);
        for (int i = 1; i < n; ++i) {
            cin >> p[i];
            p[i]--;
        }
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            adj[p[i]].emplace_back(i);
        }
        vector<map<int, int64_t>> dp(n);
        function<int64_t(int, int)> solve = [&](int v, int t) {
            if (dp[v].count(t)) {
                return dp[v][t];
            }
            dp[v][t] = 1LL * t * s[v];
            int m = (int)adj[v].size();
            vector<pair<int64_t, int64_t>> ans;
            for (auto& u : adj[v]) {
                ans.emplace_back(solve(u, t / m), solve(u, (t + m - 1) / m));
            }
            sort(ans.begin(), ans.end(), [&](pair<int64_t, int64_t> x, pair<int64_t, int64_t> y) {
                    return (x.second - x.first > y.second - y.first);
                });
            for (int j = 0; j < m; ++j) {
                if (j < t % m) {
                    dp[v][t] += ans[j].second;
                } else {
                    dp[v][t] += ans[j].first;
                }
            }
            return dp[v][t];
        };
        cout << solve(0, k) << "\n";
    }
}
