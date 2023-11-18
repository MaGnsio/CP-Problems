/**
 *    author:  MaGnsi0
 *    created: 10.11.2023 16:57:57
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7, M = 128;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int64_t>> dp(n, vector<int64_t>(M, -1));
        function<int64_t(int, int)> solve = [&](int x, int y) {
            if (x == n) {
                return int64_t(__builtin_popcount(y) == k);
            }
            if (dp[x][y] != -1) {
                return dp[x][y];
            }
            dp[x][y] = (solve(x + 1, y) + solve(x + 1, y & a[x])) % MOD;
            return dp[x][y];
        };
        cout << solve(0, M - 1) << "\n";
    }
}
