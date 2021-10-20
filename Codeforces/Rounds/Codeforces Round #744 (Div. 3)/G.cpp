/**
 *    author:  MaGnsi0
 *    created: 29/09/2021 16:25:19
**/
#include <bits/stdc++.h>
using namespace std;

const int OO = 1e9, X = 4e3 + 3;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        vector<vector<int>> dp(n + 1, vector<int>(X, OO));
        dp[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < X; ++j) {
                if (dp[i][j] == OO) {
                    continue;
                }
                /*left*/ {
                    int left = max(j - v[i], 0);
                    dp[i + 1][left] = min(dp[i + 1][left], dp[i][j] + v[i]);
                }
                /*right*/ {
                    int right = j + v[i];
                    if (right < X) {
                        dp[i + 1][right] = min(dp[i + 1][right], max(dp[i][j] - v[i], 0)); 
                    }
                }
            }
        }
        int res = OO;
        for (int j = 0; j < X; ++j) {
            res = min(res, dp[n][j] + j);
        }
        cout << res << "\n";
    }
}
