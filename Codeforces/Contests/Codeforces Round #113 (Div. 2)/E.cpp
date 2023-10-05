/**
 *    author:  MaGnsi0
 *    created: 19.05.2022 01:05:10
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, j = 0;
    cin >> n;
    vector<vector<int64_t>> dp(4, vector<int64_t>(2));
    dp[0][j] = 1, dp[1][j] = dp[2][j] = dp[3][j] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[0][j ^ 1] = dp[1][j] + dp[2][j] + dp[3][j];
        dp[0][j ^ 1] %= MOD;
        dp[1][j ^ 1] = dp[0][j] + dp[2][j] + dp[3][j];
        dp[1][j ^ 1] %= MOD;
        dp[2][j ^ 1] = dp[1][j] + dp[0][j] + dp[3][j];
        dp[2][j ^ 1] %= MOD;
        dp[3][j ^ 1] = dp[1][j] + dp[2][j] + dp[0][j];
        dp[3][j ^ 1] %= MOD;
        j ^= 1;
    }
    cout << dp[0][j];
}
