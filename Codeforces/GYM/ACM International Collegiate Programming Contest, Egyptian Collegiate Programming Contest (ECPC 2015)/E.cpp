/**
 *    author:  MaGnsi0
 *    created: 20.06.2023 18:28:18
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 700, offset = 350;
const int dx[2] = {1, 0};
const int dy[2] = {0, 1};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));
        vector<vector<int>> b(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int x; cin >> x;
                while (x % 2 == 0) { x /= 2, a[i][j]++; } 
                while (x % 3 == 0) { x /= 3, b[i][j]++; }
            }
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(N, -1)));
        function<int(int, int, int)> solve = [&](int x, int y, int z) {
            if (x >= n || y >= m) { return 0; }
            int O = a[x][y] + (z > 0) * z;
            int X = b[x][y] + (z < 0) * abs(z);
            if (dp[x][y][z + offset] != -1) { return dp[x][y][z + offset]; }
            dp[x][y][z + offset] = min(O, X) + max(solve(x + 1, y, O - X), solve(x, y + 1, O - X));
            return dp[x][y][z + offset];
        };
        cout << solve(0, 0, 0) << "\n";
    }
}
