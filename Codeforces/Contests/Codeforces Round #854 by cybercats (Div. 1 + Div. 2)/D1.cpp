/**
 *    author:  MaGnsi0
 *    created: 27.02.2023 17:40:54
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e15;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1, -1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            a[i]--;
        }
        vector<int64_t> b(k), c(k);
        for (int i = 0; i < k; ++i) {
            cin >> b[i];
        }
        for (int i = 0; i < k; ++i) {
            cin >> c[i];
        }
        vector<vector<int64_t>> dp(n + 1, vector<int64_t>(n + 1, OO));
        dp[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == OO) { continue; }
                int x = max(i, j) + 1;
                dp[i][x] = min(dp[i][x], dp[i][j] + (a[j] == a[x] ? c[a[x]] : b[a[x]]));
                dp[x][j] = min(dp[x][j], dp[i][j] + (a[i] == a[x] ? c[a[x]] : b[a[x]]));
            }
        }
        int64_t ans = OO;
        for (int i = 0; i <= n; ++i) {
            ans = min(ans, dp[i][n]);
            ans = min(ans, dp[n][i]);
        }
        cout << ans << "\n";
    }
}
