/**
 *    author:  MaGnsi0
 *    created: 04.11.2021 14:07:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, t;
    double p;
    cin >> n >> p >> t;
    vector<vector<double>> dp(t + 1, vector<double>(n + 1, 0.0));
    dp[1][1] = p, dp[1][0] = (1 - p);
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (j == n) {
                dp[i + 1][j] += dp[i][j];
            } else {
                dp[i + 1][j + 1] += dp[i][j] * p;
                dp[i + 1][j] += dp[i][j] * (1 - p);
            }
        }
    }
    double res = 0;
    for (int j = 0; j <= n; ++j) {
        res += dp[t][j] * j;
    }
    cout << fixed << setprecision(6) << res;
}
