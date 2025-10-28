/**
 *    author:  MaGnsi0
 *    created: 28.10.2025 18:39:06
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e17;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n; n++;
        vector<int64_t> a(n), b(n);
        for (int i = 1; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i < n; ++i) {
            cin >> b[i];
        }
        vector<int64_t> dp(n, -1);
        function<int64_t(int)> solve = [&](int i) {
            if (i + 1 == n) { return int64_t(0); }
            if (dp[i] != -1) { return dp[i]; }
            dp[i] = OO;
            if (a[i] <= a[i + 1]) {
                dp[i] = min(dp[i], solve(i + 1));
            }
            int64_t sum = 0;
            for (int j = i + 1; j < n; ++j) {
                if (a[i] <= a[j]) {
                    dp[i] = min(dp[i], solve(j) + sum);
                }
                sum += b[j];
            }
            dp[i] = min(dp[i], sum);
            return dp[i];
        };
        int64_t ans = solve(0);
        cout << ans << "\n";
    }
}
