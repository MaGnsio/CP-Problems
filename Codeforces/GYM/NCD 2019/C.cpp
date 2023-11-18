/**
 *    author:  MaGnsi0
 *    created: 15.10.2023 21:50:29
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int64_t> dp(n, 1);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (a[j] > a[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        vector<int64_t> cnt(n, 0);
        for (int i = n - 1; i >= 0; --i) {
            if (dp[i] == 1) {
                cnt[i] = 1;
                continue;
            }
            for (int j = i + 1; j < n; ++j) {
                if (a[j] > a[i] && dp[j] == dp[i] - 1) {
                    cnt[i] += cnt[j];
                    cnt[i] %= MOD;
                }
            }
        }
        int64_t ans = 0, LIS = *max_element(dp.begin(), dp.end());
        for (int i = 0; i < n; ++i) {
            ans += (dp[i] == LIS) * cnt[i];
            ans %= MOD;
        }
        cout << LIS << " " << ans << "\n";
    }
}
