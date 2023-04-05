/**
 *    author:  MaGnsi0
 *    created: 18.02.2023 09:56:32
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int64_t power(int64_t b, int64_t p) {
    int64_t ans = 1;
    while (p) {
        if (p & 1) { ans = ans * b % MOD; }
        b = b * b % MOD;
        p /= 2;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<int64_t>> dp(n, vector<int64_t>(1 << n, 0));
    vector<int64_t> I(1 << n);
    iota(I.begin(), I.end(), 0);
    sort(I.begin(), I.end(), [&](int i, int j) {
            return __builtin_popcount(i) < __builtin_popcount(j);
        });
    vector<int> b(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j]) { b[i] |= (1 << j); }
        }
    }
    dp[0][1] = 1;
    for (int i = 1; i < (1 << n); ++i) {
        int mask = I[i];
        for (int j = 0; j < n; ++j) {
            if (!((mask >> j) & 1)) { continue; }
            if (dp[j][mask] == 0) { continue; }
            int k = (mask ^ b[j]) & b[j];
            int64_t p = power(__builtin_popcount(k), MOD - 2);
            while (k) {
                int x = __builtin_ctz(k);
                dp[x][mask | (1 << x)] += p * dp[j][mask];
                dp[x][mask | (1 << x)] %= MOD;
                k -= (1 << x);
            }
        }
    }
    vector<int64_t> ans(n, 0);
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            int k = (i ^ b[j]) & b[j];
            if (k == 0) {
                ans[j] += dp[j][i];
                ans[j] %= MOD;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
}
