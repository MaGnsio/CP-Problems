/**
 *    author:  MaGnsi0
 *    created: 08.02.2023 11:18:26
**/
#include <bits/stdc++.h>

using namespace std;

const int dx[3] = {-1, 0, 1};
const int dy[3] = {1, 1, 1};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<string> a(3);
        for (int i = 0; i < 3; ++i) {
            cin >> a[i];
        }
        function<bool(int, int, int)> F = [&](int fx, int y, int tx) {
            vector<string> b = a;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (b[i][j] != '.' && y) {
                        if (j - 2 * y >= 0) { b[i][j - 2 * y] = b[i][j]; }
                        b[i][j] = '.';
                    }
                }
            }
            if (b[fx][y + 1] != '.') {
                return false;
            }
            if (b[tx][y + 1] != '.') {
                return false;
            }
            for (int j = 0; j < n; ++j) {
                if (b[tx][j] != '.') {
                    if (j - 1 == y + 1 || j - 2 == y + 1) {
                        return false;
                    }
                }
            }
            return true;
        };
        vector<vector<bool>> dp(3, vector<bool>(n, false));
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] == 's') {
                    a[i][j] = '.';
                    dp[i][j] = true;
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < 3; ++i) {
                if (dp[i][j] == false) {
                    continue;
                }
                for (int k = 0; k < 3; ++k) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni < 0 || ni >= 3) { continue; }
                    if (nj < 0 || nj >= n) { continue; }
                    if (dp[ni][nj]) { continue; }
                    dp[ni][nj] = F(i, j, ni);
                }
            }
        }
        cout << (dp[0][n - 1] || dp[1][n - 1] || dp[2][n - 1] ? "YES" : "NO") << "\n";
    }
}
