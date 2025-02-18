/**
 *    author:  MaGnsi0
 *    created: 18.02.2025 16:58:23
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector dp(n, vector<int64_t>(4, -1));
        function<int64_t(int, int)> solve = [&](int j, int s) {
            if (j == n) { return int64_t(s == 3); }
            if (dp[j][s] != -1) { return dp[j][s]; }
            dp[j][s] = solve(j + 1, s);
            if (s == 2 && a[j] == 3) {
                dp[j][s] += solve(j + 1, 3); dp[j][s] %= MOD;
            } else if (s == 2 && a[j] == 2) {
                dp[j][s] += solve(j + 1, 2); dp[j][s] %= MOD;
            } else if (s == 1 && a[j] == 2) {
                dp[j][s] += solve(j + 1, 2); dp[j][s] %= MOD;
            } else if (s == 0 && a[j] == 1) {
                dp[j][s] += solve(j + 1, 1); dp[j][s] %= MOD;
            }
            return dp[j][s];
        };
        int64_t ans = solve(0, 0);
        cout << ans << "\n";
    }
}
