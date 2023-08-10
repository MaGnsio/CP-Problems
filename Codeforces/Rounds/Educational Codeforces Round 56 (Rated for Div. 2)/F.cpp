/**
 *    author:  MaGnsi0
 *    created: 03.08.2023 16:45:00
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; a[i]--;
    }
    if (m == 1) {
        cout << 0;
        return 0;
    }
    vector<vector<int>> b(k);
    for (int i = 0; i < n; ++i) {
        if (a[i] == -2) { continue; }
        for (int j = 0; j < k; ++j) {
            if (a[i] == j) { continue; }
            b[j].push_back(i);
        }
    }
    vector<int64_t> sum_dp(n);
    vector<vector<int64_t>> dp(n, vector<int64_t>(k));
    for (int j = 0; j < k; ++j) {
        dp[n - 1][j] = (a[n - 1] == j || a[n - 1] == -2);
    }
    for (int j = 0; j < k; ++j) {
        sum_dp[n - 1] += dp[n - 1][j];
    }
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < k; ++j) {
            if (a[i] != j && a[i] != -2) { continue; }
            int low = i + 1;
            int high = upper_bound(b[j].begin(), b[j].end(), i) - b[j].begin();
            if (high == (int)b[j].size()) {
                high = n - 1;
                dp[i][j] += (n - i < m);
            } else {
                high = b[j][high];
            }
            high = min(high, i + m - 1);
            dp[i][j] += (sum_dp[low] - (high + 1 < n ? sum_dp[high + 1] : 0) + MOD) % MOD;
            dp[i][j] %= MOD;
            dp[i][j] -= (dp[low][j] - (high + 1 < n ? dp[high + 1][j] : 0) + MOD) % MOD;
            dp[i][j] += MOD;
            dp[i][j] %= MOD;
        }
        for (int j = 0; j < k; ++j) {
            dp[i][j] += dp[i + 1][j];
            dp[i][j] %= MOD;
        }
        for (int j = 0; j < k; ++j) {
            sum_dp[i] += dp[i][j];
            sum_dp[i] %= MOD;
        }
    }
    int64_t ans = (sum_dp[0] - (n > 1 ? sum_dp[1] : 0) + MOD) % MOD;
    cout << ans;
}
