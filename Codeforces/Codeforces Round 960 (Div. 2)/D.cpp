/**
 *    author:  MaGnsi0
 *    created: 22.11.2024 18:19:06
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t M = 3, OO = 1e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector dp(n, vector<int64_t>(3, -1));
        function<int64_t(int, int)> solve = [&](int j, int s) {
            if (j == n) { return int64_t(0); }
            if (dp[j][s] != -1) { return dp[j][s]; }
            if (a[j] == 0) {
                return dp[j][s] = solve(j + 1, 0);
            }
            if (s == 0) {
                dp[j][s] = solve(j + 1, a[j] <= 2 ? 1 : 0) + 1;
            } else if (s == 1) {
                if (a[j] <= 2) {
                    dp[j][s] = solve(j + 1, 0);
                } else if (a[j] <= 4) {
                    dp[j][s] = solve(j + 1, 2) + 1;
                } else {
                    dp[j][s] = solve(j + 1, 0) + 1;
                }
            } else {
                if (a[j] <= 4) {
                    dp[j][s] = solve(j + 1, 1) + 1;
                } else {
                    dp[j][s] = solve(j + 1, 0) + 1;
                }
            }
            return dp[j][s];
        };
        int64_t ans = solve(0, 0);
        cout << ans << "\n";
    }
}
