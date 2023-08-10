/**
 *    author:  MaGnsi0
 *    created: 09.07.2023 05:37:35
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 2000, MOD = 998244353;

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
    vector<int64_t> F(N, 1), F_(N, 1);
    for (int i = 1; i < N; ++i) {
        F[i] = F[i - 1] * i % MOD;
        F_[i] = power(F[i], MOD - 2);
    }
    function<int64_t(int, int)> C = [&](int n, int k) {
        if (k > n) { return int64_t(0); }
        return F[n] * F_[k] % MOD * F_[n - k] % MOD;
    };
    function<int64_t(int, int)> C_ = [&](int n, int k) {
        if (k > n) { return int64_t(0); }
        return F_[n] * F[k] % MOD * F[n - k] % MOD;
    };
    function<int64_t(int, int, int)> G = [&](int n, int k, int max) {
        int64_t ans = 0;
        for (int i = 0; i <= k; ++i) {
            if (n < i * (max + 1)) { break; }
            int64_t val = C(k, i);
            val *= C((n - i * (max + 1)) + k - 1, k - 1);
            val %= MOD;
            if (i % 2 == 0) {
                ans += val;
                ans %= MOD;
            } else {
                ans -= val;
                ans += MOD;
                ans %= MOD;
            }
        }
        return ans;
    };
    function<int64_t(int, int, int)> P = [&](int n, int k, int max) {
        int64_t ans = ((G(n, k, max) - G(n, k, max - 1)) % MOD + MOD) % MOD;
        ans *= C_(n + k - 1, k - 1);
        ans %= MOD;
        return ans;
    };
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int64_t> dp(n + 1, -1);
        function<int64_t(int)> solve = [&](int x) {
            if (x == 0) { return int64_t(0); }
            if (dp[x] != -1) { return dp[x]; }
            dp[x] = 0;
            for (int i = 1; i <= x; ++i) {
                dp[x] += P(x, k, i) * (solve(x - i) + 1) % MOD;
                dp[x] %= MOD;
            }
            return dp[x];
        };
        cout << solve(n) << "\n";
    }
}
