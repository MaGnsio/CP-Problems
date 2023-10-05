/**
 *    author:  MaGnsi0
 *    created: 02.10.2023 19:57:06
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 1e4 + 4, OO = 1e17;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, w, b, x;
    cin >> n >> w >> b >> x;
    vector<int64_t> a(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    vector<int64_t> dp(N, -OO);
    dp[0] = w;
    for (int i = 0; i < n; ++i) {
        vector<int64_t> new_dp(N);
        for (int j = 0; j < N; ++j) {
            new_dp[j] = dp[j] + !!i * x;
        }
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k <= min(a[i],  int64_t(j)); ++k) {
                if (dp[j - k] < 0) { continue; }
                int64_t mana = min(w + (j - k) * b, dp[j - k] + !!i * x) - k * c[i];
                if (mana >= 0) {
                    new_dp[j] = max(new_dp[j], mana);
                }
            }
        }
        dp = new_dp;
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        ans = max(ans, (dp[i] >= 0) * i);
    }
    cout << ans;
}
