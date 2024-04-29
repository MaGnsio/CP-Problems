/**
 *    author:  MaGnsi0
 *    created: 29.04.2024 17:58:10
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = INT64_MAX;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int64_t>> dp(n, vector<int64_t>(k + 1, -OO));
        function<int64_t(int, int)> solve = [&](int x, int y) {
            if (x == n) {
                return int64_t(0);
            }
            if (dp[x][y] != -OO) {
                return dp[x][y];
            }
            dp[x][y] = solve(x + 1, y);
            if (x + 1 < n && y) {
                dp[x][y] = min(dp[x][y], solve(x + 1, y - 1) + a[x + 1] - a[x]);
            }
            int64_t minus = 0;
            for (int64_t t = 1; t <= y; ++t) {
                if (x + t >= n) { break; }
                dp[x][y] = min(dp[x][y], solve(x + t, y - t) + t * a[x + t] - (minus + a[x]));
                minus += a[x + t];
                dp[x][y] = min(dp[x][y], solve(x + t + 1, y - t) + t * a[x] - minus);
            }
            return dp[x][y];
        };
        cout << accumulate(a.begin(), a.end(), int64_t(0)) + solve(0, k) << "\n";
    }
}
