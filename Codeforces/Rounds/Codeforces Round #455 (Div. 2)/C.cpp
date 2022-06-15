/**
 *    author:  MaGnsi0
 *    created: 19.05.2022 02:32:37
**/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<char> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] == 'f') {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j - 1];
            }
        } else {
            dp[i][n - 1] = dp[i - 1][n - 1];
            for (int j = n - 2; j >= 0; --j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j + 1];
                dp[i][j] %= MOD;
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < n; ++j) {
        ans += dp[n - 1][j];
        ans %= MOD;
    }
    cout << ans;
}
