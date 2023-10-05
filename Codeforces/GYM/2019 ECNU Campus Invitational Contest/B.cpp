/**
 *    author:  MaGnsi0
 *    created: 10.09.2023 00:04:12
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<vector<double>> dp(N, vector<double>(2, -1));
    function<double(int, int)> solve = [&](int x, int y) {
        if (x == 0) {
            return 1.0 * (y == 0);
        }
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        dp[x][y] = 0;
        if (y == 1) {
            dp[x][y] = 1 - solve(x - 1, 0);
        } else {
            dp[x][0] = 1.0 * (1 + x - x * solve(x - 1, 1)) / (x + 2);
        }
        return dp[x][y];
    };
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int x = 0, y = 0;
        for (int i = 0; i < n; ++i) {
            x += s[i] == '1' && t[i] == '1';
            y += s[i] == '1' && t[i] == '0';
        }
        cout << fixed << setprecision(10) << solve(x, y) << "\n";
    }
}
