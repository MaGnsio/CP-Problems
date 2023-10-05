/**
 *    author:  MaGnsi0
 *    created: 04.07.2022 16:34:11
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i]--;
        }
        vector<vector<bool>> can_remove(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            int max_cnt = 0;
            vector<int> cnt(n, 0);
            for (int j = i + 1; j < n; j += 2) {
                max_cnt = max({max_cnt, ++cnt[a[j]], ++cnt[a[j - 1]]});
                can_remove[i][j] = (2 * max_cnt <= j - i + 1);
            }
        }
        vector<vector<int>> b(n);
        for (int i = 0; i < n; ++i) {
            b[i].push_back(-1);
        }
        for (int i = 0; i < n; ++i) {
            b[a[i]].push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            b[i].push_back(n);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int m = (int)b[i].size();
            vector<int> dp(m, -OO);
            dp[0] = 0;
            for (int j = 1; j < m; ++j) {
                for (int k = 0; k < j; ++k) {
                    if (b[i][j] - b[i][k] == 1 || can_remove[b[i][k] + 1][b[i][j] - 1]) {
                        dp[j] = max(dp[j], dp[k] + 1);
                    }
                }
            }
            ans = max(ans, dp[m - 1] - 1);
        }
        cout << ans << "\n";
    }
}
