/**
 *    author:  MaGnsi0
 *    created: 02.12.2024 22:20:38
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e16;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int k; cin >> k;
    vector<int64_t> t(n), f(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> f[i];
    }
    vector<int64_t> p(k), d(k), c(k);
    for (int i = 0; i < k; ++i) {
        cin >> p[i] >> d[i] >> c[i];
    }
    vector<int64_t> dp(n + 1, OO); dp[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        dp[i] = dp[i + 1] + f[i];
        for (int j = 0; j < k; ++j) {
            int i_ = min(i + d[j], lower_bound(t.begin(), t.end(), t[i] + p[j]) - t.begin());
            dp[i] = min(dp[i], dp[i_] + c[j]);
        }
    }
    int64_t ans = dp[0];
    cout << ans;
}
