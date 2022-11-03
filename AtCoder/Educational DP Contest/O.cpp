/**
 *    author:  MaGnsi0
 *    created: 20.09.2022 20:39:58
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

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
    int m = (1 << n);
    vector<int64_t> dp(m, -1);
    function<int64_t(int)> solve = [&](int mask) {
        if (mask == m - 1) {
            return int64_t(1);
        }
        if (dp[mask] != -1) {
            return dp[mask];
        }
        int j = __builtin_popcount(mask);
        dp[mask] = 0;
        for (int i = 0; i < n; ++i) {
            if ((a[i][j] == 1) && !((mask >> i) & 1)) {
                dp[mask] += solve(mask | (1 << i));
                dp[mask] %= MOD;
            }
        }
        return dp[mask];
    };
    cout << solve(0);
}
