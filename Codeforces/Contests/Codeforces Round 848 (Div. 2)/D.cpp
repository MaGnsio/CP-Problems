/**
 *    author:  MaGnsi0
 *    created: 10.10.2023 22:00:47
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
    int T;
    cin >> T;
    while (T--) {
        int n, m = 0;
        string s, t;
        cin >> n >>  s >> t;
        for (int i = 0; i < n; ++i) {
            m += s[i] != t[i];
        }
        int64_t n_inv = power(n, MOD - 2);
        vector<int64_t> dp(n + 1);
        dp[n] = 1;
        for (int64_t x = n - 1; x; --x) {
            int64_t val = n_inv * (n - x) % MOD;
            int64_t up = (x * n_inv % MOD + val * (dp[x + 1] + 1) % MOD) % MOD;
            int64_t down = (MOD - val + 1) % MOD;
            dp[x] = up * power(down, MOD - 2) % MOD;
        }
        int64_t ans = 0;
        for (int i = 1; i <= m; ++i) {
            ans = (ans + dp[i]) % MOD;
        }
        cout << ans << "\n";
    }
}
