/**
 *    author:  MaGnsi0
 *    created: 14.11.2021 16:54:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<long double>> dp(n, vector<long double>(n, 0.0));
    for (int i = 1; i < n; ++i) {
        dp[0][i] = 1.0 / (1.0 * (n - 1));
    }
    for (int i = 1; i < n; ++i) {
        dp[i][i] += (1 - dp[i - 1][i]) / (1.0 * i);
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }
            dp[i][j] += dp[i - 1][i] / (1.0 * (n - i));
        }
        for (int j = 0; j < n; ++j) {
            dp[i][j] += dp[i - 1][j];
        }
    }
    cout << fixed << setprecision(12) << dp[n - 2][n - 1];
}
