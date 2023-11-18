/**
 *    author:  MaGnsi0
 *    created: 07.10.2023 12:04:44
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        int n = (int)s.size();
        int m = (int)t.size();
        vector<vector<int>> next(26, vector<int>(n + 1, -1));
        for (int i = 0; i < n; ++i) {
            next[s[i] - 'a'][i] = i;
        }
        for (int j = 0; j < 26; ++j) {
            next[j][n] = n;
            for (int i = n - 1; i >= 0; --i) {
                next[j][i] = (next[j][i] != -1 ? next[j][i] : next[j][i + 1]);
            }
        }
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, n));
        dp[0][0] = -1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j <= m; ++j) {
                dp[i + 1][j] = dp[i][j];
                if (j && dp[i][j - 1] < n) {
                    dp[i + 1][j] = min(dp[i][j], next[t[i] - 'a'][dp[i][j - 1] + 1]);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= m; ++i) {
            if (dp[m][i] != n) { ans = i; }
        }
        cout << ans << "\n";
    }
}
