/**
 *    author:  MaGnsi0
 *    created: 11.09.2022 15:58:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1, n;
    while ((cin >> n) && (n != 0)) {
        vector<double> x(2 * n), y(2 * n);
        for (int i = 0; i < 2 * n; ++i) {
            string _;
            cin >> _;
            cin >> x[i] >> y[i];
        }
        vector<double> dp(1 << (2 * n), 1e18);
        vector<bool> done(1 << (2 * n), false);
        function<double(int)> solve = [&](int mask) {
            if (__builtin_popcount(mask) == 2 * n) {
                return 0.0;
            }
            if (done[mask]) {
                return dp[mask];
            }
            done[mask] = true;
            for (int i = 0; i < 2 * n; ++i) {
                for (int j = i + 1; j < 2 * n; ++j) {
                    if (!((mask >> i) & 1) && !((mask >> j) & 1)) {
                        dp[mask] = min(dp[mask], sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) + solve(mask | (1 << i) | (1 << j)));
                    }
                }
            }
            return dp[mask];
        };
        cout << "Case " << T++ << ": ";
        cout << fixed << setprecision(2) << solve(0) << "\n";
    }
}
