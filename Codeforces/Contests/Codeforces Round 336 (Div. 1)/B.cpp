/**
 *    author:  MaGnsi0
 *    created: 05.10.2023 15:36:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, -1));
    function<int(int, int)> solve = [&](int x, int y) {
        if (x > y) { return 0; }
        if (x == y) { return 1; }
        if (dp[x][y] != -1) { return dp[x][y]; }
        dp[x][y] = solve(x + 1, y) + 1;
        for (int j = x + 1; j <= y; ++j) {
            if (a[x] != a[j]) { continue; }
            dp[x][y] = min(dp[x][y], solve(x + 1, j - 1) + solve(j + 1, y) + (j == x + 1));
        }
        return dp[x][y];
    };
    cout << solve(0, n - 1);
}
