/**
 *    author:  MaGnsi0
 *    created: 15.09.2024 20:20:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int k; cin >> k;
        int n; cin >> n;
        int m; cin >> m;
        vector<int> a(k);
        for (int i = 0; i < k; ++i) {
            cin >> a[i];
        }
        vector<vector<int>> b(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> b[i][j];
            }
        }
        vector dp(k, vector(n, vector<int>(m, -1)));
        function<int(int, int, int)> solve = [&](int j, int x, int y) {
            if (j == k || x == n || y == m) { return 0; }
            if (dp[j][x][y] != -1) { return dp[j][x][y]; }
            dp[j][x][y] = 0;
            dp[j][x][y] |= solve(j, x + 1, y);
            dp[j][x][y] |= solve(j, x, y + 1);
            dp[j][x][y] |= (b[x][y] == a[j] ? solve(j + 1, x + 1, y + 1) ^ 1 : 0);
            return dp[j][x][y];
        };
        char ans = solve(0, 0, 0) ? 'T' : 'N';
        cout << ans << "\n";
    }
}
