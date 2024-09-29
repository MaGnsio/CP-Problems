/**
 *    author:  MaGnsi0
 *    created: 29.09.2024 19:49:38
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 1024, MOD = 1e9 + 7;

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
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> a(n), p(n), p_(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            p[i] = p[i] * power(10000, MOD - 2) % MOD;
            p_[i] = (MOD - p[i] + 1) % MOD;
        }
        vector<vector<int64_t>> dp(2, vector<int64_t>(N, 0)); dp[1][0] = 1;
        for (int j = 0; j < n; ++j) {
            for (int val = 0; val < N; ++val) {
                dp[j & 1][val] = 0;
            }
            for (int val = 0; val < N; ++val) {
                dp[j & 1][val ^ a[j]] += p[j] * dp[(j & 1) ^ 1][val]; dp[j & 1][val ^ a[j]] %= MOD;
                dp[j & 1][val] += p_[j] * dp[(j & 1) ^ 1][val] % MOD; dp[j & 1][val] %= MOD;
            }
        }
        int64_t ans = 0;
        for (int val = 0; val < N; ++val) {
            ans = (ans + dp[(n - 1) & 1][val] * val * val % MOD) % MOD;
        }
        cout << ans << "\n";
    }
}
