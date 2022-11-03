/**
 *    author:  MaGnsi0
 *    created: 05.03.2022 13:54:55
**/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(9, 0));
    for (int i = 0; i < 9; ++i) {
        dp[0][i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 9; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j - 1 >= 0) {
                dp[i][j] += dp[i - 1][j - 1];
                dp[i][j] %= MOD;
            }
            if (j + 1 < 9) {
                dp[i][j] += dp[i - 1][j + 1];
                dp[i][j] %= MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 9; ++i) {
        ans += dp[n - 1][i];
        ans %= MOD;
    }
    cout << ans;
}
