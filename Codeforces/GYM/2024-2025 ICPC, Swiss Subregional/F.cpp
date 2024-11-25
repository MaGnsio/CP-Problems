/**
 *    author:  MaGnsi0
 *    created: 25.11.2024 21:15:05
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 5006, OO = N - 1;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n + 1, OO), b(n + 1, OO);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            b[i] = min(a[i], b[i - 1]);
        }
        vector dp(n + 1, vector<int>(N, -1));
        function<int(int, int)> solve = [&](int i, int x) {
            if (i == n + 1) { return 0; }
            if (dp[i][x] != -1) { return dp[i][x]; }
            int y = b[i - 1];
            dp[i][x] = 1e9;
            dp[i][x] = min(dp[i][x], solve(i + 1, max(min(x, a[i]), y)) + max(a[i] - x, 0));
            dp[i][x] = min(dp[i][x], solve(i + 1, max(x, min(y, a[i]))) + max(a[i] - y, 0));
            return dp[i][x];
        };
        int ans = solve(1, OO);
        cout << ans << "\n";
    }
}
