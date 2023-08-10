/**
 *    author:  MaGnsi0
 *    created: 06.08.2023 09:32:19
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int64_t power(int64_t b, int64_t p) {
    if (b == 0) { return 0; }
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
    int T;
    cin >> T;
    while (T--) {
        int64_t n, m, k, x;
        cin >> n >> m >> k >> x;
        vector<int64_t> ways(k + 1);
        for (int i = 1; i <= k; ++i) {
            ways[i] = (power(i, m) - power(i - 1, m) + MOD) % MOD;
        }
        vector<vector<int64_t>> dp(2, vector<int64_t>(k + 1, 0));
        int j = 0;
        for (int i = 1; i <= k; ++i) {
            dp[j][i] = ways[i];
            dp[j][i] += dp[j][i - 1];
            dp[j][i] %= MOD;
        }
        for (int _ = 2; _ <= n; ++_) {
            for (int i = 1; i <= k; ++i) {
                int low = max(int64_t(1), i - x);
                int high = min(int64_t(k), i + x);
                dp[j ^ 1][i] = ways[i] * (dp[j][high] - dp[j][low - 1] + MOD) % MOD;
            }
            j ^= 1;
            for (int i = 1; i <= k; ++i) {
                dp[j][i] += dp[j][i - 1];
                dp[j][i] %= MOD;
            }
        }
        int64_t ans = dp[j][k];
        cout << ans << "\n";
    }
}
