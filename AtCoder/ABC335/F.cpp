/**
 *    author:  MaGnsi0
 *    created: 06.01.2024 15:07:41
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t SQRT = 500, MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int64_t> dp(n);
    vector<vector<int64_t>> sum(SQRT, vector<int64_t>(SQRT));
    for (int i = n - 1; i >= 0; --i) {
        dp[i] = 1;
        if (a[i] >= SQRT) {
            for (int j = i + a[i]; j < n; j += a[i]) {
                dp[i] += dp[j];
                dp[i] %= MOD;
            }
        } else {
            dp[i] += sum[a[i]][i % a[i]];
            dp[i] %= MOD;
        }
        for (int j = 1; j < SQRT; ++j) {
            sum[j][i % j] += dp[i];
            sum[j][i % j] %= MOD;
        }
    }
    cout << dp[0];
}
