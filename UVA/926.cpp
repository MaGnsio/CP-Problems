/**
 *    author:  MaGnsi0
 *    created: 08.09.2022 01:56:23
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
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        int w;
        cin >> w;
        vector<vector<int>> a(n + 2, vector<int>(n + 2, 0));
        for (int i = 0; i < w; ++i) {
            char d;
            int x, y;
            cin >> x >> y >> d;
            if (d == 'N') {
                a[x][y] |= 1;
            }
            if (d == 'E') {
                a[x][y] |= 2;
            }
            if (d == 'S') {
                a[x][y - 1] |= 1;
            }
            if (d == 'W') {
                a[x - 1][y] |= 2;
            }
        }
        vector<vector<int64_t>> dp(n + 2, vector<int64_t>(n + 2, -1));
        function<int64_t(int, int)> solve = [&](int x, int y) {
            if (!x || x > n || !y || y > n) {
                return dp[x][y] = 0;
            }
            if (x == ex && y == ey) {
                return dp[x][y] = 1;
            }
            if (dp[x][y] != -1) {
                return dp[x][y];
            }
            dp[x][y] = 0;
            if (!(a[x][y] & 1)) {
                dp[x][y] += solve(x, y + 1);
            }
            if (!(a[x][y] & 2)) {
                dp[x][y] += solve(x + 1, y);
            }
            return dp[x][y];
        };
        cout << solve(sx, sy) << "\n";
    }
}
