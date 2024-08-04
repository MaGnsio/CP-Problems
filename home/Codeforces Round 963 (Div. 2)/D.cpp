/**
 *    author:  MaGnsi0
 *    created: 04.08.2024 17:57:49
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int X = (n / k), Y = n - k * X;
        if (Y == 0) { X -= 1, Y += k; }
        int m = min(X, Y);
        if (X == 0) {
            sort(a.begin(), a.end());
            cout << a[(n - 1) / 2] << "\n";
            continue;
        }
        int64_t low = *min_element(a.begin(), a.end());
        int64_t high = *max_element(a.begin(), a.end());
        int64_t ans = low;
        function<bool(int64_t)> F = [&](int64_t x) {
            vector<int64_t> b(n, 0);
            for (int i = 0; i < n; ++i) {
                b[i] = a[i] < x ? -1 : 1;
            }
            vector<vector<int64_t>> dp(n + 1, vector<int64_t>(m + 1, -OO)); dp[n][0] = 0;
            for (int i = n - 1; i >= 0; --i) {
                for (int j = 0; j < m; ++j) {
                    if (X < Y) {
                        dp[i][j] = dp[i + 1][j] + b[i];
                        if (i + k - 1 < n) {
                            dp[i][j + 1] = max(dp[i][j], dp[i + k][j]);
                        }
                    } else {
                        dp[i][j + 1] = max(dp[i + 1][j] + b[i], dp[i][j + 1]);
                        if (i + k - 1 < n) {
                            dp[i][j] = max(dp[i][j], dp[i + k][j]);
                        }
                    }
                }
            }
            return dp[0][m] > 0;
        };
        while (low <= high) {
            int64_t mid = (low + high) / 2;
            if (F(mid)) {
                ans = mid, low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << ans << "\n";
    }
}
