/**
 *    author:  MaGnsi0
 *    created: 26/09/2021 16:49:13
**/
#include <bits/stdc++.h>
using namespace std;

const int N = 600;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int x, y;
    cin >> x >> y;
    int t, d;
    cin >> t >> d;
    vector<vector<int>> dp(N, vector<int>(N, -1));
    dp[1][x] = x;
    for (int i = 1; i + 1 < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (dp[i][j] == -1) {
                continue;
            }
            for (int k = 0; k <= d; ++k) {
                if (j + k < N) {
                    dp[i + 1][j + k] = max(dp[i + 1][j + k], dp[i][j] + j + k);
                }
                if (j - k >= 0) {
                    dp[i + 1][j - k] = max(dp[i + 1][j - k], dp[i][j] + j - k);
                }
            }
        }
    }
    cout << dp[t][y];
}
