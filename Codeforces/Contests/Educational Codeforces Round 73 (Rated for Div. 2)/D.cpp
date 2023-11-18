/**
 *    author:  MaGnsi0
 *    created: 18.10.2023 22:08:08
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }
        vector<vector<vector<int64_t>>> dp(n, vector<vector<int64_t>>(5, vector<int64_t>(5, -1)));
        function<int64_t(int, int, int)> solve = [&](int x, int y, int z) {
            if (x == n - 1) { return b[x] * y; }
            if (dp[x][y][z] != -1) { return dp[x][y][z]; }
            dp[x][y][z] = OO;
            int64_t p = (x ? a[x - 1] : -1) + z;
            for (int i = 0; i < 5; ++i) {
                if (y + i > 4) { break; }
                if (a[x] + y + i == p) { continue; }
                if (a[x] + y + i == a[x + 1]) {
                    dp[x][y][z] = min(dp[x][y][z], solve(x + 1, 1, y + i) + b[x] * (y + i));
                } else {
                    dp[x][y][z] = min(dp[x][y][z], solve(x + 1, 0, y + i) + b[x] * (y + i));
                }
            }
            return dp[x][y][z];
        };
        cout << solve(0, 0, 0) << "\n";
    }
}
