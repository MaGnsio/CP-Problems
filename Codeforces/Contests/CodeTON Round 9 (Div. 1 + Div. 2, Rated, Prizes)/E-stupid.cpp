/**
 *    author:  MaGnsi0
 *    created: 23.11.2024 18:48:13
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector dp(2, vector(3, vector<int64_t>(n + 1, 0)));
        for (int inv = 0; inv < 3; ++inv) {
            for (int t = 0; t <= n; ++t) {
                dp[n & 1][inv][t] = 1;
            }
        }
        for (int i = n - 1; i >= 2; --i) {
            int j = i & 1, k = j ^ 1;
            for (int inv = 0; inv < 3; ++inv) {
                for (int t = 0; t <= n; ++t) {
                    int64_t& res = dp[j][inv][t]; res = 0;
                    if (t + 1 <= n) {
                        res += dp[k][inv][t + 1]; res %= MOD;
                    }
                    for (int add_inv = 1; add_inv <= i - t; ++add_inv) {
                        res += dp[k][min(inv + add_inv, 2)][min(inv + add_inv, 2) == 1 ? 1 : 0]; res %= MOD;
                    }
                }
            }
        }
        int64_t ans = dp[0][0][1] % MOD;
        cout << ans << "\n";
    }
}
