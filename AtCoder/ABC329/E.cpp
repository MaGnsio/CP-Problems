/**
 *    author:  MaGnsi0
 *    created: 18.11.2023 14:11:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    string s; cin >> s;
    string t; cin >> t;
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    function<int(int, int)> solve = [&](int x, int y) {
        if (x == n) { return 1; }
        if (dp[x][y] != -1) { return dp[x][y]; }
        dp[x][y] = 0;
        if (y) {
            for (int j = 0; j < m; ++j) {
                for (int k = 1; j + k - 1 < m && x + k - 1 < n; ++k) {
                    if (s.substr(x, k) == t.substr(j, k) && x + (m - j) - 1 < n) {
                        dp[x][y] |= solve(x + k, j + k == m);
                    }
                }
            }
        } else if (x + m - 1 < n) {
            for (int k = 1; k < m; ++k) {
                if (s.substr(x, k) == t.substr(0, k)) {
                    dp[x][y] |= solve(x + k, 0);
                }
            }
            if (s.substr(x, m) == t) {
                dp[x][y] |= solve(x + m, 1);
            }
        }
        return dp[x][y];
    };
    cout << (solve(0, 0) ? "Yes" : "No");
}
