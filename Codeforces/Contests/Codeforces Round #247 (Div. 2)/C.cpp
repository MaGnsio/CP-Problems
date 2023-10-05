/**
 *    author:  MaGnsi0
 *    created: 30/09/2021 00:10:57
**/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, k, d;
    cin >> n >> k >> d;
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {//we add edge of length j to the bath of length i
            if (i - j < 0) {
                break;
            }
            if (j < d) {//then we get can't get dp[i - j][0]
                dp[i][0] += dp[i - j][0];
                dp[i][0] %= MOD;
                dp[i][1] += dp[i - j][1];
                dp[i][1] %= MOD;
            } else {//both dp[i - j][1], dp[i - j][0] are counted
                dp[i][1] += dp[i - j][0];
                dp[i][1] %= MOD;
                dp[i][1] += dp[i - j][1];
                dp[i][1] %= MOD;
            }
        }
    }
    cout << dp[n][1];
}
