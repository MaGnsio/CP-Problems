/**
 *    author:  MaGnsi0
 *    created: 24.08.2024 11:25:54
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e15;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int64_t> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<vector<int64_t>> dp(n, vector<int64_t>(n, -1));
    function<int64_t(int, int)> solve = [&](int i, int j) {
        if (i == n) { return int64_t(0); }
        if (dp[i][j] != -1) { return dp[i][j]; }
        dp[i][j] = solve(i + 1, j) + abs(a[i + 1] - a[i]);
        dp[i][j] = min(dp[i][j], solve(i + 1, i) + abs(a[i + 1] - a[j]));
        return dp[i][j];
    };
    cout << solve(0, 0);
}
