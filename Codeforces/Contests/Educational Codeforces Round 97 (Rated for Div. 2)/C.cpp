/**
 *    author:  MaGnsi0
 *    created: 03.03.2022 10:55:45
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<vector<int>> dp(n, vector<int>(2 * n + 1, OO));
        for (int i = 1; i <= 2 * n; ++i) {
            dp[0][i] = abs(a[0] - i);
            dp[0][i] = min(dp[0][i], dp[0][i - 1]);
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= 2 * n; ++j) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + abs(a[i] - j));
            }
            for (int j = 1; j <= 2 * n; ++j) {
                dp[i][j] = min(dp[i][j], dp[i][j - 1]);
            }
        }
        cout << dp[n - 1][2 * n] << "\n";
    }
}
