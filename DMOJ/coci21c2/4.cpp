/**
 *    author:  MaGnsi0
 *    created: 07.04.2023 05:00:29
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 1e6, MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, m;
    cin >> n >> m;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    function<int64_t(int64_t, int64_t)> power = [&](int64_t b, int64_t p) {
        int64_t res = 1;
        while (p) {
            if (p & 1) { res = res * b % MOD; }
            b = b * b % MOD;
            p /= 2;
        }
        return res;
    };
    vector<int64_t> f(N, 1), f_(N, 1);
    for (int64_t i = 1; i < N; ++i) {
        f[i] = i * f[i - 1];
        f[i] %= MOD;
        f_[i] = power(f[i], MOD - 2);
    }
    function<int64_t(int64_t, int64_t)> C = [&](int64_t x, int64_t y) {
        return f[x] * f_[y] % MOD * f_[x - y] % MOD;
    };
    vector<vector<vector<int64_t>>> dp(n, vector<vector<int64_t>>(n + 1, vector<int64_t>(m + 1, -1)));
    function<int64_t(int64_t, int64_t, int64_t)> solve = [&](int64_t i, int64_t j, int64_t k) {
        //dp[i][j][k] = dp[magnet index][number of groups][remaining length]
        if (i == n) {
            return (j == 1 ? C(k + n, n) : int64_t(0));
        }
        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        dp[i][j][k] = 0;
        if (k) { //add a new group
            dp[i][j][k] += (j + 1) * solve(i + 1, j + 1, k - 1);
            dp[i][j][k] %= MOD;
        }
        if (j >= 2 && 2 * a[i] - 1 <= k) {
            dp[i][j][k] += (j - 1) * solve(i + 1, j - 1, k - 2 * a[i] + 1);
            dp[i][j][k] %= MOD;
        }
        if (j && a[i] <= k) {
            dp[i][j][k] += 2 * j * solve(i + 1, j, k - a[i]);
            dp[i][j][k] %= MOD;
        }
        return dp[i][j][k];
    };
    cout << solve(0, 0, m);
}
