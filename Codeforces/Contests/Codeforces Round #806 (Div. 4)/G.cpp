/**
 *    author:  MaGnsi0
 *    created: 13.07.2022 18:17:56
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e15, M = 32;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, k;
        cin >> n >> k;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int64_t>> dp(M, vector<int64_t>(n + 1, -OO));
        dp[0][0] = 0;
        for (int j = 1; j <= n; ++j) {
            for (int i = 0; i < M; ++i) {
                dp[i][j] = max(dp[i][j], dp[i][j - 1] - k + (a[j - 1] >> i));
                if (i) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + (a[j - 1] >> i));
                }
                if (i == M - 1) {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + (a[j - 1] >> i));
                }
            }
        }
        int64_t ans = 0;
        for (int i = 0; i < M; ++i) {
            ans = max(ans, dp[i][n]);
        }
        cout << ans << "\n";
    }
}
