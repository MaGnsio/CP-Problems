/**
 *    author:  MaGnsi0
 *    created: 17.06.2023 15:14:02
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int64_t> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    vector<vector<int64_t>> dp(n, vector<int64_t>(2, -1));
    function<int64_t(int, int)> solve = [&](int x, int y) {
        if (x == n) {
            return int64_t(0);
        }
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        dp[x][y] = solve(x + 1, y);
        if (y == 0 || (y == 1 && a[x] == 0)) {
            dp[x][y] = max(dp[x][y], solve(x + 1, a[x]) + b[x]);
        }
        return dp[x][y];
    };
    int64_t ans = solve(0, 0);
    cout << ans;
}
