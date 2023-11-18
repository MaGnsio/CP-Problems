/**
 *    author:  MaGnsi0
 *    created: 07.11.2023 16:15:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<double> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<vector<double>> dp(n + 1, vector<double>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = max(dp[i - 1][j], 0.9 * dp[i - 1][j - 1] + a[i]);
        }
    }
    double ans = -1e18;
    for (int k = 1; k <= n; ++k) {
        double x = 0;
        for (int i = 1; i <= k; ++i) {
            x += pow(0.9, k - i);
        }
        ans = max(ans, (dp[n][k] / x) - (1200 / sqrt(k)));
    }
    cout << fixed << setprecision(8) << ans;
}
