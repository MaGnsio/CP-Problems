/**
 *    author:  MaGnsi0
 *    created: 14.07.2024 01:51:39
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; a[i]--;
        }
        vector<vector<int>> dp(n, vector<int>(n, -1));
        function<int(int, int)> solve = [&](int l, int r) {
            if (l > r) { return 0; }
            int& res = dp[l][r];
            if (res != -1) { return res; }
            res = OO;
            for (int m = l + 1; m <= r; ++m) {
                if ((l - a[l] < 0) || ((l - a[l]) & 1)) { continue; }
                if (2 * solve(l + 1, m - 1) > l - a[l]) { continue; }
                if (solve(m + 1, r) == OO) { continue; }
                int op = max((l - a[l]) / 2, solve(m + 1, r) - (m - l + 1) / 2);
                res = min(res, op);
            }
            return res;
        };
        vector<int> ans(n, 0);
        for (int i = 0; i < n; ++i) {
            ans[i] = (i ? ans[i - 1] : 0);
            for (int j = 0; j < i; ++j) {
                int prev = (j ? ans[j - 1] : 0);
                if (prev < solve(j, i)) { continue; }
                ans[i] = max(ans[i], prev + (i - j + 1) / 2);
            }
        }
        cout << ans[n - 1] << "\n";
    }
}
