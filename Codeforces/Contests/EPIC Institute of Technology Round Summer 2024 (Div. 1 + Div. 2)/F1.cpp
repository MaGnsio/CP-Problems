/**
 *    author:  MaGnsi0
 *    created: 14.07.2024 00:29:42
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
            cin >> a[i]; a[i]--;
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        function<int(int, int, int)> solve = [&](int l, int r, int op) {
            if (l >= r) { return 0; }
            int& res = dp[l][r][op];
            if (res != -1) { return res; }
            res = solve(l + 1, r, op);
            for (int m = l + 1; m <= r; ++m) {
                if ((l - a[l] < 0) || ((l - a[l]) & 1) || (l - a[l] > 2 * op)) { continue; }
                if (2 * solve(l + 1, m - 1, min(op, (l - a[l]) / 2)) != (m - l - 1)) { continue; }
                int add_op = (m - l - 1) / 2 + 1;
                res = max(res, solve(m + 1, r, op + add_op) + add_op);
            }
            return res;
        };
        cout << solve(0, n - 1, 0) << "\n";
    }
}
