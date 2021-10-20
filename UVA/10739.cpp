/**
 *    author:  MaGnsi0
 *    created: 07/09/2021 18:25:57
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        string s;
        cin >> s;
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i + 1 < n; ++i) {
            dp[i][i + 1] = (s[i] != s[i + 1]);
        }
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                } else {
                    //adding is never necessary
                    //                remove i        change i        remove j
                    dp[i][j] = min({dp[i + 1][j], dp[i + 1][j - 1], dp[i][j - 1]}) + 1;
                }
            }
        }
        cout << "Case " << t << ": " << dp[0][n - 1] << "\n";
    }
}
