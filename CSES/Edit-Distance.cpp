/**
 *    author:  MaGnsi0
 *    created: 02.01.2022 23:14:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e8));
    dp[0][0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            }
            if (j) {
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
            if (i && j) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s[i - 1] != t[j - 1]));
            }
        }
    }
    cout << dp[n][m];
}
