/**
 *    author:  MaGnsi0
 *    created: 27.11.2024 01:20:22
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e8;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    function<vector<vector<int>>()> solve = [&]() {
        vector<vector<int>> dp(n, vector<int>(m, OO));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 || j == 0 || a[i - 1][j] != a[i][j] || a[i][j - 1] != a[i][j]) {
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
        return dp;
    };
    auto dp1 = solve();
    for(int i = 0; i < n; ++i) {
        reverse(a[i].begin(), a[i].end());
    }
    auto dp2 = solve();
    for (int i = 0; i < n; ++i) {
        reverse(dp2[i].begin(), dp2[i].end());
    }
    reverse(a.begin(), a.end());
    auto dp3 = solve();
    for (int i = 0; i < n; ++i) {
        reverse(dp3[i].begin(), dp3[i].end());
    }
    reverse(dp3.begin(), dp3.end());
    for (int i = 0; i < n; ++i) {
        reverse(a[i].begin(), a[i].end());
    }
    auto dp4 = solve();
    reverse(dp4.begin(), dp4.end());
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans += min({dp1[i][j], dp2[i][j], dp3[i][j], dp4[i][j]});
        }
    }
    cout << ans;
}
