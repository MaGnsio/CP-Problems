/**
 *    author:  MaGnsi0
 *    created: 26.05.2025 18:41:38
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t x, y, k;
        cin >> x >> y >> k;
        int64_t g = __gcd(x, y);
        x /= g, y /= g;
        function<int64_t(int64_t)> F = [&](int64_t n) {
            vector<int64_t> divisors;
            for (int i = 2; i <= min(n, k); ++i) {
                if (n % i == 0) {
                    divisors.push_back(i);
                }
            }
            vector<int64_t> dp(n + 1, -1);
            function<int64_t(int64_t)> solve = [&](int64_t x) {
                if (x == 1) { return int64_t(0); }
                if (dp[x] != -1) { return dp[x]; }
                dp[x] = 200;
                for (int64_t d : divisors) {
                    if (x % d == 0) {
                        dp[x] = min(dp[x], solve(x / d) + 1);
                    }
                }
                return dp[x];
            };
            return solve(n);
        };
        int64_t ans = F(x) + F(y);
        if (ans >= 200) { ans = -1; }
        cout << ans << "\n";
    }
}
