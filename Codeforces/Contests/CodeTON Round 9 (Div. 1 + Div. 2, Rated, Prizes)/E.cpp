/**
 *    author:  MaGnsi0
 *    created: 24.11.2024 18:21:10
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> dp1(n + 1), dp2(n + 1);
        for (int64_t i = n, sum = 0; i > 0; --i) {
            dp1[i] = (i * sum + 1) % MOD;
            sum += dp1[i]; sum %= MOD;
        }
        for (int64_t i = 3; i <= n; ++i) {
            dp2[i] = ((i - 1) * (i - 2) / 2 - 1) % MOD;
        }
        int64_t ans = n - 1;
        for (int i = 3; i <= n; ++i) {
            ans += dp1[i] * dp2[i] % MOD;
            ans %= MOD;
        }
        cout << ans << "\n";
    }
}
