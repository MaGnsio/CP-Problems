/**
 *    author:  MaGnsi0
 *    created: 02/10/2021 19:51:19
**/
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    string s;
    while (cin >> s) {
        int n = (int)s.size();
        vector<vector<long long>> dp(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        for (int len = 3; len <= n; len += 2) {
            for (int i = 0, j = i + len - 1; j < n; ++i, ++j) {
                for (int k = i + 2; k <= j; k += 2) {
                    if (s[i] == s[k] && s[k] == s[j]) {
                        dp[i][j] = (dp[i][j] + dp[i + 1][k - 1] * dp[k][j]) % MOD;
                    }
                }
            }
        }
        cout << dp[0][n - 1] << "\n";
    }
}
