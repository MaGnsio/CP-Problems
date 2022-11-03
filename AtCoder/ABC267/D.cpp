/**
 *    author:  MaGnsi0
 *    created: 03.09.2022 13:58:11
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e15;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int64_t>> dp(n, vector<int64_t>(m + 1, -OO));
    function<int64_t(int, int)> solve = [&](int x, int y) {
        if (y == m) {
            return int64_t(0);
        }
        if (dp[x][y] != -OO) {
            return dp[x][y];
        }
        dp[x][y] = a[x] * (y + 1) + solve(x + 1, y + 1);
        if (n - x - 1 >= m - y) {
            dp[x][y] = max(dp[x][y], solve(x + 1, y));
        }
        return dp[x][y];
    };
    cout << solve(0, 0);
}
