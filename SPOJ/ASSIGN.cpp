/**
 *    author:  MaGnsi0
 *    created: 25.12.2021 18:31:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        int m = (1 << n);
        vector<int64_t> dp(m, -1);
        function<int64_t(int)> solve = [&](int y) {
            int x = __builtin_popcount(y);
            if (x == n) {
                return int64_t(1);
            }
            if (dp[y] != -1) {
                return dp[y];
            }
            dp[y] = 0;
            for (int i = 0; i < n; ++i) {
                if (a[x][i] && !(y & (1 << i))) {
                    dp[y] += solve(y | (1 << i));
                }
            }
            return dp[y];
        };
        cout << solve(0) << "\n";
    }
}
