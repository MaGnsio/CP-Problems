/**
 *    author:  MaGnsi0
 *    created: 01.09.2023 22:52:11
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int64_t> Pk(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        Pk[i] = Pk[i - 1] * k % MOD;
    }
    vector<vector<int64_t>> dp(n + 1, vector<int64_t>(k));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        int64_t sum = 0;
        for (int j = k - 1; j >= 1; --j) {
            sum = (sum + dp[i][j]) % MOD;
            dp[i + 1][j] = sum;
        }
        for (int j = 0; j < k; ++j) {
            dp[i + 1][(j + 1) % k] += (k - j) * dp[i][j];
            dp[i + 1][(j + 1) % k] %= MOD;
        }
    }
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += dp[i][k - 1] * Pk[n - (i + 1)] % MOD;
        ans %= MOD;
    }
    cout << ans;
}
