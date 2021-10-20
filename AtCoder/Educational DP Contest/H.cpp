/**
 *    author:  MaGnsi0
 *    created: 10/09/2021 21:16:48
**/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int h, w;
    cin >> h >> w;
    vector<vector<char>> g(h, vector<char>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> g[i][j];
        }
    }
    vector<vector<int>> dp(h, vector<int>(w, 0));
    dp[0][0] = 1;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (g[i][j] == '#' || !(i + j)) {
                continue;
            }
            if (i) {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= MOD;
            }
            if (j) {
                dp[i][j] += dp[i][j - 1];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[h - 1][w - 1];
}
