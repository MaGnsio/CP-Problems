/**
 *    author:  MaGnsi0
 *    created: 08.09.2022 00:47:47
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int64_t>> dp(n, vector<int64_t>(k + 1, 0));
    for (int i = 0; i <= min(k, a[0]); ++i) {
        dp[0][k - i] = 1; 
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp[i - 1][j] += dp[i - 1][j - 1];
            dp[i - 1][j] %= MOD;
        }
        for (int j = 0; j <= k; ++j) {
            dp[i][j] += dp[i - 1][min(k, j + a[i])];
            dp[i][j] %= MOD;
            if (j) {
                dp[i][j] -= dp[i - 1][j - 1];
                dp[i][j] += MOD;
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[n - 1][0];
}
