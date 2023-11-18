/**
 *    author:  MaGnsi0
 *    created: 23.09.2023 11:16:13
**/
#include <bits/stdc++.h>

using namespace std;

const int M = 41;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> next(n, vector<int>(M, n));
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < M; ++j) {
            if (a[i + 1] >> j & 1) {
                next[i][j] = i + 1;
            } else {
                next[i][j] = next[i + 1][j];
            }
        }
    }
    vector<int64_t> dp(n, -1);
    function<int64_t(int)> solve = [&](int x) {
        if (x == n) { return int64_t(0); }
        if (dp[x] != -1) { return dp[x]; }
        dp[x] = solve(x + 1);
        for (int b = 0; b < M; ++b) {
            if (next[x][b] != n) {
                dp[x] = max(dp[x], solve(next[x][b]) + (a[x] & a[next[x][b]]));
            }
        };
        return dp[x];
    };
    cout << solve(0);
}
