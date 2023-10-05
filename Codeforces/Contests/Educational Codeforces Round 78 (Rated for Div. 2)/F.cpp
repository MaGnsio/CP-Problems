/**
 *    author:  MaGnsi0
 *    created: 05.08.2023 14:43:04
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int64_t power(int64_t b, int64_t p) {
    int64_t res = 1;
    while (p) {
        if (p & 1) { res = res * b % MOD; }
        b = b * b % MOD;
        p /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, m, k;
    cin >> n >> m >> k;
    vector<vector<int64_t>> dp(k + 1, vector<int64_t>(k + 1));
    dp[0][0] = 1;
    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (i + 1 <= k && j + 1 <= k) {
                dp[i + 1][j + 1] += (n - j) * dp[i][j];
                dp[i + 1][j + 1] %= MOD;
            }
            if (i + 1 <= k) {
                dp[i + 1][j] += j * dp[i][j];
                dp[i + 1][j] %= MOD;
            }
        }
    }
    int64_t ans = 0;
    for (int i = 1; i <= k; ++i) {
        ans += dp[k][i] * power(power(m, i), MOD - 2);
        ans %= MOD;
    }
    cout << ans;
}
