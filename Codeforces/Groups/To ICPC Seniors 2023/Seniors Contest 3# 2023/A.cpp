/**
 *    author:  MaGnsi0
 *    created: 07.02.2023 18:47:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(m + 1, {0, -1}));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp[i + 1][j] = dp[i][j];
            if (j >= b[i]) {
                int x = a[i] + dp[i][j - b[i]].first;
                int y = (dp[i][j - b[i]].second == -1 ? i : dp[i][j - b[i]].second);
                dp[i + 1][j] = max(dp[i + 1][j], make_pair(x, y));
            }
        }
    }
    int res = dp[n][m].first, ans = n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (dp[i][j].first == res) {
                ans = min(ans, i - dp[i][j].second);
            }
        }
    }
    cout << ans;
}
