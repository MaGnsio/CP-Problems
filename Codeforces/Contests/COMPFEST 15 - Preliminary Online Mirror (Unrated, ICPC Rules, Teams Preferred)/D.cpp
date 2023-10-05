/**
 *    author:  MaGnsi0
 *    created: 03.09.2023 15:59:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    int k; cin >> k;
    vector<vector<int64_t>> a(m, vector<int64_t>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[j][i];
        }
    }
    for (int j = 0; j < m; ++j) {
        sort(a[j].rbegin(), a[j].rend());
        for (int i = 1; i < n; ++i) {
            a[j][i] += a[j][i - 1];
        }
    }
    vector<vector<int64_t>> dp(m, vector<int64_t>(k + 1, -1));
    function<int64_t(int, int)> solve = [&](int x, int y) {
        if (x == m) { return int64_t(0); }
        if (dp[x][y] != -1) { return dp[x][y]; }
        int new_y;
        if (x < m - k + 1) {
            new_y = y - (y == k) + 1;
        } else {
            new_y = min(y, m - x);
        }
        dp[x][y] = solve(x + 1, new_y);
        for (int i = 1; i <= min(new_y, n); ++i) {
            dp[x][y] = max(dp[x][y], solve(x + 1, new_y - i) + a[x][i - 1]);
        }
        return dp[x][y];
    };
    cout << solve(0, 0);
}
