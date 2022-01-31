/**
 *    author:  MaGnsi0
 *    created: 03.01.2022 15:30:54
**/
#include <bits/stdc++.h>

using namespace std;

int solve(vector<vector<int>>& dp, int x, int y) {
    if (dp[x][y] != -1) {
        return dp[x][y];
    }
    if (x == y) {
        return dp[x][y] = 0;
    }
    dp[x][y] = 1e7;
    for (int i = 1; i <= x / 2; ++i) {
        dp[x][y] = min(dp[x][y], solve(dp, i, y) + solve(dp, x - i, y) + 1);
    }
    for (int j = 1; j <= y / 2; ++j) {
        dp[x][y] = min(dp[x][y], solve(dp, x, j) + solve(dp, x, y - j) + 1);
    }
    return dp[x][y];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << solve(dp, n, m);
}
