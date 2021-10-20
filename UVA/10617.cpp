/**
 *    author:  MaGnsi0
 *    created: 06/09/2021 19:18:19
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<vector<long long>> dp(n, vector<long long>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - (len > 2) * dp[i + 1][j - 1];
                if (s[i] == s[j]) {
                    dp[i][j] += 1 + (len > 2) * dp[i + 1][j - 1];
                }
            }
        }
        cout << dp[0][n - 1] << "\n";
    }
}
