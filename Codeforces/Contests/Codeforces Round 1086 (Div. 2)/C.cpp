/**
 *    author:  MaGnsi0
 *    created: 19.03.2026 06:05:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> C(n), P(n);
        for (int i = 0; i < n; ++i) {
            cin >> C[i] >> P[i];
        }
        vector<bool> visited(n);
        vector<double> dp(n);
        function<double(int)> solve = [&](int j) {
            if (j == n) { return 0.0; }
            if (visited[j]) { return dp[j]; }
            visited[j] = true;
            dp[j] = solve(j + 1);
            dp[j] = max(dp[j], C[j] + solve(j + 1) - (1.0 * P[j] / 100.0) * solve(j + 1));
            return dp[j];
        };
        cout << fixed << setprecision(6) << solve(0) << "\n";
    }
}
