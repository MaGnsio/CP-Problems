/**
 *    author:  MaGnsi0
 *    created: 29.05.2024 21:54:34
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 101;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int>> dp(n, vector<int>(N, -1));
        function<int(int, int)> solve = [&](int x, int y) {
            if (x == n) { return 1; }
            if (dp[x][y] != -1) { return dp[x][y]; }
            dp[x][y] = 0;
            if (a[x] >= y) {
                dp[x][y] |= solve(x + 1, a[x]);
            }
            if (a[x] >= 10 && y <= (a[x] / 10) && (a[x] / 10) <= (a[x] % 10)) {
                dp[x][y] |= solve(x + 1, a[x] % 10);
            }
            return dp[x][y];
        };
        cout << (solve(0, 0) ? "YES" : "NO") << "\n";
    }
}
