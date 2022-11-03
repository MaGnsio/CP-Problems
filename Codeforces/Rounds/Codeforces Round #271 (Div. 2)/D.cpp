/**
 *    author:  MaGnsi0
 *    created: 08.09.2022 02:48:42
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 1e5 + 5, MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T, K;
    cin >> T >> K;
    vector<int64_t> dp(N);
    dp[0] = 1;
    for (int i = 1; i < N; ++i) {
        dp[i] = dp[i - 1] + (i - K >= 0 ? dp[i - K] : 0);
        dp[i] %= MOD;
    }
    for (int i = 1; i < N; ++i) {
        dp[i] += dp[i - 1];
        dp[i] %= MOD;
    }
    while (T--) {
        int a, b;
        cin >> a >> b;
        cout << (dp[b] - dp[a - 1] + MOD) % MOD << "\n";
    }
}
