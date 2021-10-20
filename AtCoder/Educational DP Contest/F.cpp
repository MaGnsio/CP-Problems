/**
 *    author:  MaGnsi0
 *    created: 29/07/2021 17:04:23
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + (s[i - 1] == t[j - 1]));
        }
    }
    string lcs = "";
    for (int i = n, j = m, k = dp[n][m]; k; --i, --j, --k) {
        while (s[i - 1] != t[j - 1]) {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
        lcs.push_back(s[i - 1]);
    }
    reverse(lcs.begin(), lcs.end());
    cout << lcs;
}
