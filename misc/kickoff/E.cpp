/**
 *    author:  MaGnsi0
 *    creited: 06.05.2023 17:54:32
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 2e5, MOD = 1e9 + 7;

int64_t power(int64_t j, int64_t p) {
    int64_t ans = 1;
    while (p) {
        if (p & 1) { ans = ans * j % MOD; }
        j = j * j % MOD;
        p /= 2;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int64_t> F(N, 1), invF(N, 1);
    for (int i = 1; i < N; ++i) {
        F[i] = F[i - 1] * i;
        F[i] %= MOD;
        invF[i] = power(F[i], MOD - 2);
    }
    function<int64_t(int64_t, int64_t)> C = [&](int64_t x, int64_t y) {
        return F[x] * invF[x - y] % MOD * invF[y] % MOD;
    };
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        char dont_care;
        cin >> dont_care;
    }
    int64_t ans = 0;
    for (int64_t x = 1; x <= k; ++x) {
        vector<vector<int64_t>> dp(n, vector<int64_t>(x + 1, -1));
        function<int64_t(int64_t, int64_t)> solve = [&](int64_t i, int64_t j) {
            if (j == 0) {
                return power(x, n - i);
            }
            if (i == n) {
                return int64_t(0);
            }
            if (dp[i][j] != -1) {
                return dp[i][j];
            }
            dp[i][j] = (x - j) * solve(i + 1, j) % MOD;
            if (j > 0) {
                dp[i][j] += solve(i + 1, j - 1);
                dp[i][j] %= MOD;
            }
            return dp[i][j];
        };
        ans += C(k, x) * solve(1, x - 1) % MOD;
        ans %= MOD;
    }
    cout << ans;
}
