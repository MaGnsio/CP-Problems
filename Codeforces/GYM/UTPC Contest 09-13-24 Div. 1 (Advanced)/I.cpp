/**
 *    author:  MaGnsi0
 *    created: 27.11.2024 21:10:54
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 2e12;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int x; cin >> x; x--;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector dp(n, vector(n, vector<int64_t>(2, OO))); dp[x][x][0] = dp[x][x][1] = 0;
    for (int l = 1; l <= n; ++l) {
        for (int i = 0; i + l - 1 < n; ++i) {
            int j = i + l - 1;
            if (dp[i][j][0] != OO) {
                int64_t t = dp[i][j][0];
                if (i && t + 1 < a[i - 1]) {
                    dp[i - 1][j][0] = min(dp[i - 1][j][0], t + 1);
                }
                if (j + 1 < n && t + (j - i + 1) < a[j + 1]) {
                    dp[i][j + 1][1] = min(dp[i][j + 1][1], t + (j - i + 1));
                }
            }
            if (dp[i][j][1] != OO) {
                int64_t t = dp[i][j][1];
                if (i && t + (j - i + 1) < a[i - 1]) {
                    dp[i - 1][j][0] = min(dp[i - 1][j][0], t + (j - i + 1));
                }
                if (j + 1 < n && t + 1 < a[j + 1]) {
                    dp[i][j + 1][1] = min(dp[i][j + 1][1], t + 1);
                }
            }
        }
    }
    int64_t ans = min(dp[0][n - 1][0], dp[0][n - 1][1]);
    cout << (ans == OO ? -1 : ans);
}
