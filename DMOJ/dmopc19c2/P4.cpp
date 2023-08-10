/**
 *    author:  MaGnsi0
 *    created: 27.03.2023 23:25:39
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, T, Q;
    cin >> N >> T >> Q;
    vector<int64_t> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    vector<int64_t> dp(T + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = T; j >= a[i]; --j) {
            dp[j] += dp[j - a[i]];
            dp[j] %= MOD;
        }
    }
    while (Q--) {
        int x, y, z;
        cin >> x >> y >> z;
        z -= a[x - 1], z -= a[y - 1];
        if (z < 0) {
            cout << 0 << "\n";
            continue;
        }
        for (int j = a[x - 1]; j <= T; ++j) {
            dp[j] -= dp[j - a[x - 1]];
            dp[j] += MOD;
            dp[j] %= MOD;
        }
        for (int j = a[y - 1]; j <= T; ++j) {
            dp[j] -= dp[j - a[y - 1]];
            dp[j] += MOD;
            dp[j] %= MOD;
        }
        int64_t ans = 0;
        for (int i = 0; i <= z; ++i) {
            ans += dp[i];
            ans %= MOD;
        }
        cout << ans << "\n";
        for (int j = T; j >= a[x - 1]; --j) {
            dp[j] += dp[j - a[x - 1]];
            dp[j] %= MOD;
        }
        for (int j = T; j >= a[y - 1]; --j) {
            dp[j] += dp[j - a[y - 1]];
            dp[j] %= MOD;
        }
    }
}
