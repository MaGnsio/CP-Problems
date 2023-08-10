/**
 *    author:  MaGnsi0
 *    created: 24.06.2023 17:17:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i]--;
        }
        vector<set<int>> b(n);
        for (int i = 0; i < n; ++i) {
            b[a[i]].insert(i);
        }
        vector<vector<int>> dp(n, vector<int>(2, -1));
        function<int(int, int)> solve = [&](int j, int x) {
            if (j == n) { return 0; }
            if (dp[j][x] != -1) { return dp[j][x]; }
            dp[j][x] = solve(j + 1, 0);
            auto it = b[a[j]].upper_bound(j);
            if (it != b[a[j]].end()) {
                int k = *it;
                dp[j][x] = max(dp[j][x], (k - j + 1 - x) + solve(k, 1));
            }
            return dp[j][x];
        };
        int ans = solve(0, 0);
        cout << ans << "\n";
    }
}
