/**
 *    author:  MaGnsi0
 *    created: 28.10.2024 17:42:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector dp(n, vector<int64_t>(2, -1));
        function<int64_t(int, int)> solve = [&](int i, int j) {
            if (i == n) { return int64_t(0); }
            if (dp[i][j] != -1) { return dp[i][j]; }
            dp[i][j] = 1e18;
            if (i + 1 < n) {
                dp[i][j] = min(dp[i][j], max(a[i + 1] - a[i], solve(i + 2, j)));
            }
            if (j == 0) {
                dp[i][j] = min(dp[i][j], max(int64_t(1), solve(i + 1, 1)));
            }
            return dp[i][j];
        };
        int64_t ans = solve(0, 0);
        cout << ans << "\n";
    }
}

