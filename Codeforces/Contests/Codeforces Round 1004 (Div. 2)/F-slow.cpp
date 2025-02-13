/**
 *    author:  MaGnsi0
 *    created: 13.02.2025 21:44:00
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        vector<int> p(n + 1);
        for (int i = 1; i <= n; ++i) {
            p[i] = p[i - 1] ^ a[i];
        }
        vector<map<int, int64_t>> dp(n + 1);
        function<int64_t(int, int)> solve = [&](int i, int x) {
            if (i > n) { return int64_t(1); }
            if (dp[i].count(x)) { return dp[i][x]; }
            dp[i][x] = solve(i + 1, x);
            if ((x == p[i]) || (x == p[i - 1])) {
                dp[i][x] += 2 * solve(i + 1, p[i - 1]);
                dp[i][x] %= MOD;
            }
            return dp[i][x];
        };
        int64_t ans = solve(1, 0) % MOD;
        cout << ans << "\n";
    }
}
