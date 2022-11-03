/**
 *    author:  MaGnsi0
 *    created: 06.09.2022 22:34:02
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, s;
    while ((cin >> n >> s) && (n >= 0 && s >= 0)) {
        if (s > n) {
            cout << 0 << "\n";
            continue;
        }
        vector<vector<vector<int64_t>>> dp(n + 1, vector<vector<int64_t>>(n + 1, vector<int64_t>(2, -1)));
        function<int64_t(int, int, int)> solve = [&](int x, int y, int z) {
            if (x == n) {
                return int64_t(y == s);
            }
            int64_t& res = dp[x][y][z];
            if (res != -1) {
                return res;
            }
            res = solve(x + 1, y + z, 1) + solve(x + 1, y, 0);
            return res;
        };
        cout << solve(0, 0, 1) << "\n";
    }
}
