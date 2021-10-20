/**
 *    author:  MaGnsi0
 *    created: 29/07/2021 18:53:32
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<double> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    //dp[i][j] : i(number of coins used), j(number of head coins), j <= i
    vector<vector<double>> dp(n + 1, vector<double>(n + 1));
    dp[1][0] = 1.0 - p[0];
    dp[1][1] = p[0];
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (!j) {
                dp[i][j] = dp[i - 1][j] * (1.0 - p[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j] * (1.0 - p[i - 1])
                      + dp[i - 1][j - 1] * p[i - 1];
            }
        }
    }
    double res = 0;
    for (int i = n / 2 + 1; i <= n; ++i) {
        res += dp[n][i];
    }
    cout << fixed << setprecision(15) << res;
}
