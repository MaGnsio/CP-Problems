/**
 *    author:  MaGnsi0
 *    created: 24.10.2024 17:52:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int m = n / 2;
        vector dp(m, vector<int>(2, -1));
        function<int(int, int)> solve = [&](int i, int j) {
            if (i == m) { return (n & 1 ? (a[m] == a[i - 1]) + (a[m] == a[i + 1]) : (a[m] == a[m - 1])); }
            if (dp[i][j] != -1) { return dp[i][j]; }
            dp[i][j] = solve(i + 1, 0) + (i ? (a[i] == (j ? a[n - i] : a[i - 1])) : 0) + (i ? (a[n - i - 1] == (j ? a[i - 1] : a[n - i])) : 0);
            dp[i][j] = min(dp[i][j], solve(i + 1, 1) + (i ? (a[i] == (!j ? a[n - i] : a[i - 1])) : 0) + (i ? (a[n - i - 1] == (!j ? a[i - 1] : a[n - i])) : 0));
            return dp[i][j];
        };
        cout << solve(0, 0) << "\n";
    }
}
