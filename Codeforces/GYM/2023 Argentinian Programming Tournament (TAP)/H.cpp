/**
 *    author:  MaGnsi0
 *    created: 21.09.2023 11:24:23
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dp(2, vector<int>(n * n));
    vector<int> I(n * n), J(n * n), dpCol(n), dpRow(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            I[a[i][j] - 1] = i;
            J[a[i][j] - 1] = j;
        }
    }
    for (int i = n * n - 1; i >= 0; --i) {
        dp[0][i] = dpCol[J[i]] + 1;
        dp[1][i] = dpRow[I[i]] + 1;
        dpRow[I[i]] = max(dpRow[I[i]], dp[0][i]);
        dpCol[J[i]] = max(dpCol[J[i]], dp[1][i]);
    }
    int ans = 0;
    for (int i = 0; i < n * n; ++i) {
        ans = max(ans, dp[0][i]);
        ans = max(ans, dp[1][i]);
    }
    cout << ans;
}
