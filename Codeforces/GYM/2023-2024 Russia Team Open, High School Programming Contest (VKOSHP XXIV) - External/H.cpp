/**
 *    author:  MaGnsi0
 *    created: 24.01.2024 19:35:31
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7, N = 1005;

int64_t mex = 1, dp[N][N], MEX[N][N];

int64_t solve(int sum, int last) {
    if (sum == 0) { return int64_t(1); }
    if (last > sum) { return int64_t(0); }
    if (MEX[sum][last] == mex) { return dp[sum][last]; }
    MEX[sum][last] = mex;
    dp[sum][last] = solve(sum, last + 1);
    if (last != mex) {
        dp[sum][last] += solve(sum - last, last);
        dp[sum][last] %= MOD;
    }
    return dp[sum][last];
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n; cin >> n;
    int64_t ans = 0;
    while (true) {
        int64_t remove = mex * (mex - 1) / 2;
        if (remove > n) { break; }
        ans += mex * solve(n - remove, 1) % MOD;
        ans %= MOD;
        mex++;
    }
    cout << ans;
}
