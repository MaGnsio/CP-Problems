/**
 *    author:  MaGnsi0
 *    created: 22.09.2023 17:57:42
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 55, MOD = 1e9 + 7;

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
    function<int64_t(vector<int>, int, int)> S = [&](vector<int> f, int mode, int m) {
        int64_t ans = 0;
        for (int modeF = f[mode]; modeF <= f[mode] + m; ++modeF) {
            int n = m - (modeF - f[mode]);
            vector<int64_t> dp(n + 1, 0);
            dp[0] = 1;
            for (int d = 0; d <= 9; ++d) {
                if (d == mode) { continue; }
                int k = modeF - f[d] - (d > mode);
                if (k < 0) {
                    dp[n] = 0;
                    break;
                }
                vector<int64_t> new_dp = dp;
                for (int i = k; i >= 1; --i) {
                    for (int j = n; j >= i; --j) {
                        new_dp[j] += dp[j - i] * F_[i] % MOD;
                        new_dp[j] %= MOD;
                    }
                }
                dp = new_dp;
            }
            ans += dp[n] * F[m] % MOD * F_[modeF - f[mode]] % MOD;
            ans %= MOD;
        }
        return ans * mode % MOD;
    };
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = (int)s.size();
        int64_t ans = 0;
        for (int i = 1; i <= 9; ++i) {
            vector<int> f(10, 0); f[i] = 1;
            for (int j = 1; j < n; ++j) {
                for (int mode = 0; mode <= 9; ++mode) {
                    ans += S(f, mode, j - 1) % MOD;
                    ans %= MOD;
                }
            }
        }
        vector<int> f(10, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = (i == 0); j < s[i] - '0'; ++j) {
                vector<int> f_ = f; f_[j]++;
                for (int mode = 0; mode <= 9; ++mode) {
                    ans += S(f_, mode, n - i - 1) % MOD;
                    ans %= MOD;
                }
            }
            f[s[i] - '0']++;
        }
        for (int mode = 0; mode <= 9; ++mode) {
            ans += S(f, mode, 0) % MOD;
            ans %= MOD;
        }
        cout << ans << "\n";
    }
}
