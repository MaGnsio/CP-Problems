/**
 *    author:  MaGnsi0
 *    created: 13.08.2022 16:16:19
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int64_t ans = 0;
    for (int mod = 1; mod <= n; ++mod) {
        vector<int> b = a;
        for (int i = 0; i < n; ++i) {
            b[i] %= mod;
        }
        vector<vector<vector<int64_t>>> dp(n + 1, vector<vector<int64_t>>(mod + 1, vector<int64_t>(mod, 0)));
        dp[0][0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= mod; ++j) {
                for (int k = 0; k < mod; ++k) {
                    dp[i + 1][j][k] += dp[i][j][k];
                    dp[i + 1][j][k] %= MOD;
                    if (j < mod) {
                        dp[i + 1][j + 1][(k + b[i]) % mod] += dp[i][j][k];
                        dp[i + 1][j + 1][(k + b[i]) % mod] %= MOD;
                    }
                }
            }
        }
        ans += dp[n][mod][0];
        ans %= MOD;
    }
    cout << ans;
}
