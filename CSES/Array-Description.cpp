/**
 *    author:  MaGnsi0
 *    created: 01.01.2022 22:32:52
**/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n, vector<int>(m, 0));
    if (a[0] != 0) {
        dp[0][a[0] - 1] = 1;
    } else {
        for (int i = 0; i < m; ++i) {
            dp[0][i] = 1;
        }
    }
    for (int i = 1; i < n; ++i) {
        if (a[i] != 0) {
            if (a[i] - 2 >= 0) {
                dp[i][a[i] - 1] += dp[i - 1][a[i] - 2];
                dp[i][a[i] - 1] %= MOD;
            }
            dp[i][a[i] - 1] += dp[i - 1][a[i] - 1];
            dp[i][a[i] - 1] %= MOD;
            if (a[i] < m) {
                dp[i][a[i] - 1] += dp[i - 1][a[i]];
                dp[i][a[i] - 1] %= MOD;
            }
        } else {
            for (int j = 0; j < m; ++j) {
                if (j - 1 >= 0) {
                    dp[i][j] += dp[i - 1][j - 1];
                    dp[i][j] %= MOD;
                }
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= MOD;
                if (j + 1 < m) {
                    dp[i][j] += dp[i - 1][j + 1];
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    int res = 0;
    for (int i = 0; i < m; ++i) {
        res += dp[n - 1][i];
        res %= MOD;
    }
    cout << res;
}
