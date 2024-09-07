/**
 *    author:  MaGnsi0
 *    created: 07.09.2024 15:26:10
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n; cin >> n;
    int64_t k; cin >> k;
    vector<int64_t> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i]; a[i] += a[i - 1];
    }
    int64_t sum_all = 1;
    vector<int64_t> dp(n + 1, 0);
    map<int64_t, int64_t> sum;
    sum[a[n]] = 1;
    for (int i = n; i; --i) {
        int64_t j = k + a[i - 1];
        dp[i] = (sum_all - sum[j] + MOD) % MOD;
        sum_all += dp[i]; sum_all %= MOD;
        sum[a[i - 1]] += dp[i]; sum[a[i - 1]] %= MOD;
    }
    int64_t ans = dp[1];
    cout << ans;
}
