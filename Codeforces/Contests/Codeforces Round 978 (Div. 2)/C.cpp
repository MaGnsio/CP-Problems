/**
 *    author:  MaGnsi0
 *    created: 13.10.2024 22:49:43
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 2e5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int m; cin >> m;
        vector a(2, vector<int>(m));
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < m; ++j) {
                char c; cin >> c;
                a[i][j] = c == 'A';
            }
        }
        vector dp(m, vector(4, vector<int>(4, -1)));
        function<int(int, int, int)> solve = [&](int col, int m1, int m2) {
            if (col == m) { return 0; }
            int& res = dp[col][m1][m2];
            if (res != -1) { return res; }
            res = 0;
            if (m1 == 3) {
                res = max(res, solve(col + 1, m2, 0));
            }
            if (!(m1 >> 0 & 1) && !(m2 >> 0 & 1) && ((m1 | 1) == 3)) {
                res = max(res, solve(col + 1, m2 | 1, 1) + (a[0][col - 2] + a[0][col - 1] + a[0][col] >= 2));
            }
            if (!(m1 >> 1 & 1) && !(m2 >> 1 & 1) && ((m1 | 2) == 3)) {
                res = max(res, solve(col + 1, m2 | 2, 2) + (a[1][col - 2] + a[1][col - 1] + a[1][col] >= 2));
            }
            if ((!(m1 >> 0 & 1) && !(m2 >> 0 & 1)) && (!(m1 >> 1 & 1) && !(m2 >> 1 & 1))) {
                res = max(res, solve(col + 1, 3, 3) + (a[0][col - 2] + a[0][col - 1] + a[0][col] >= 2) + (a[1][col - 2] + a[1][col - 1] + a[1][col] >= 2));
            }
            if ((m1 == 3) && (m2 == 0)) {
                res = max(res, solve(col + 1, 3, 1) + (a[0][col - 1] + a[1][col - 1] + a[0][col] >= 2));
                res = max(res, solve(col + 1, 3, 2) + (a[0][col - 1] + a[1][col - 1] + a[1][col] >= 2));
            }
            if ((m1 == 3) && (m2 == 1)) {
                res = max(res, solve(col + 1, 3, 3) + (a[1][col - 1] + a[0][col] + a[1][col] >= 2));
            }
            if ((m1 == 3) && (m2 == 2)) {
                res = max(res, solve(col + 1, 3, 3) + (a[0][col - 1] + a[0][col] + a[1][col] >= 2));
            }
            return res;
        };
        int ans = solve(0, 3, 3);
        cout << ans << "\n";
    }
}
