/**
 *    author:  MaGnsi0
 *    created: 18.07.2023 18:15:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector<int64_t> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<vector<vector<int64_t>>> dp(n, vector<vector<int64_t>>(n, vector<int64_t>(n + 1, -1)));
    function<int64_t(int, int, int)> solve = [&](int i, int j, int x) {
        if (i > j) { return int64_t(0); }
        if (i == j) { return a[x]; }
        if (dp[i][j][x] != -1) { return dp[i][j][x]; }
        dp[i][j][x] = solve(i + 1, j, 1) + a[x];
        for (int k = i + 1; k <= j; ++k) {
            if (s[i] != s[k]) { continue; }
            dp[i][j][x] = max(dp[i][j][x], solve(i + 1, k - 1, 1) + solve(k, j, x + 1));
        }
        return dp[i][j][x];
    };
    cout << solve(0, n - 1, 1);
}
