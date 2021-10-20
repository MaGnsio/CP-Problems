/**
 *    author:  MaGnsi0
 *    created: 10/09/2021 22:50:38
**/
#include <bits/stdc++.h>
using namespace std;

const long long OO = 1e13;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, g;
    cin >> n >> m >> g;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    vector<vector<long long>> p(n, vector<long long>(m + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> p[i][j];
        }
    }
    long long dp[n][m + 1][g + 1];
    memset(dp, -1, sizeof dp);
    if (c[0]) {
        dp[0][c[0]][1] = 0;
    } else {
        for (int i = 1; i <= m; ++i) {
            dp[0][i][1] = p[0][i];
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = 1; k <= g; ++k) {
                if (c[i] != 0 && c[i] != j) {
                    continue;
                }
                long long mini = OO;
                for (int x = 1; x <= m; ++x) {
                    if (x != j && dp[i - 1][x][k - 1] != -1) {
                        mini = min(mini, dp[i - 1][x][k - 1]);
                    }
                }
                if (mini != OO && dp[i - 1][j][k] != -1) {
                    dp[i][j][k] = min(mini, dp[i - 1][j][k]) + (!c[i]) * p[i][j];
                } else if (mini != OO) {
                    dp[i][j][k] = mini + (!c[i]) * p[i][j];
                } else if (dp[i - 1][j][k] != -1) {
                    dp[i][j][k] = dp[i - 1][j][k] + (!c[i]) * p[i][j];
                }
            }
        }
    }
    long long res = OO;
    for (int i = 1; i <= m; ++i) {
        if (dp[n - 1][i][g] != -1) {
            res = min(res, dp[n - 1][i][g]);
        }
    }
    cout << (res == OO ? -1LL : res);
}
