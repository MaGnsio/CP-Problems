/**
 *    author:  MaGnsi0
 *    created: 05/09/2021 15:00:14
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<int> x(n), h(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> h[i];
    }
    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][0] = 1, dp[0][1] = (x[0] + h[0] < x[1]);
    for (int i = 1; i < n; ++i) {
        int l = x[i] - h[i];
        int r = x[i] + h[i];
        dp[i][0] = max(dp[i - 1][0] + (l > x[i - 1]), dp[i - 1][1] + (l > x[i - 1] + h[i - 1]));
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + (r < x[i + 1] || i == n - 1);
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]);
}
