/**
 *    author:  MaGnsi0
 *    created: 25.09.2023 17:47:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int64_t>> dp(n, vector<int64_t>(2, -1));
        function<int64_t(int, int)> solve = [&](int j, int took) {
            if (j == n) { return int64_t(0); }
            if (dp[j][took] != -1) { return dp[j][took]; }
            dp[j][took] = solve(j + 1, took);
            if (took) {
                dp[j][took] = max(dp[j][took], solve(j + 1, took) + a[j]);
                dp[j][took] = max(dp[j][took], solve(j + 1, took));
            } else {
                dp[j][took] = max(dp[j][took], solve(j + 1, 1) + (j % 2 == 0 ? a[j] : 0));
            }
            return dp[j][took];
        };
        cout << solve(0, 0) << "\n";
    }
}
