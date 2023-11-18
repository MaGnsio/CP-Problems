/**
 *    author:  MaGnsi0
 *    created: 05.10.2023 16:13:15
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 3e15;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    reverse(a.begin(), a.end());
    vector<vector<int64_t>> dp(n, vector<int64_t>(n, INT64_MIN));
    function<int64_t(int, int)> solve = [&](int x, int y) {
        if (x >= n) { return -OO; }
        if (x == n - 1) { return a[x]; }
        if (dp[x][y] != INT64_MIN) { return dp[x][y]; }
        dp[x][y] = solve(x + 1, y);
        dp[x][y] = max(dp[x][y], solve(x + (x - y), x) + a[x]);
        return dp[x][y];
    };
    cout << solve(1, 0) + a[0];
}
