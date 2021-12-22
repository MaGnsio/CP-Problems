/**
 *    author:  MaGnsi0
 *    created: 19.12.2021 17:04:16
**/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = (a[0][0] != '*');
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i + 1 < n && a[i + 1][j] != '*') {
                dp[i + 1][j] += dp[i][j];
                dp[i + 1][j] %= MOD;
            }
            if (j + 1 < n && a[i][j + 1] != '*') {
                dp[i][j + 1] += dp[i][j];
                dp[i][j + 1] %= MOD;
            }
        }
    }
    cout << dp[n - 1][n - 1];
}
