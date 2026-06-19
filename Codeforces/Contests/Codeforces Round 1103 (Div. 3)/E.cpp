/**
 *    author:  MaGnsi0
 *    created: 18.06.2026 19:43:46
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
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0; i < n; ++i) {
            int y = a[i], x = a[i];
            vector<int> f(n);
            for (int j = i; j < n; ++j) {
                if (f[a[j]]) { break; }
                x = min(x, a[j]), y = max(y, a[j]), f[a[j]]++;
                dp[x][y] = dp[x][y] || (y - x == j - i);
            }
        }
        int ans = 0;
        for (int x = 1; 2 * x <= n; ++x) {
            for (int i = 0; i + 2 * x <= n; ++i) {
                if (dp[i][i + x - 1] && dp[i + x][i + 2 * x - 1]) {
                    ans = x;
                }
            }
        }
        cout << ans << "\n";
    }
}
