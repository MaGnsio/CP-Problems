/**
 *    author:  MaGnsi0
 *    created: 22.09.2023 16:32:57
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t B = 130, offset = 60, MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    int64_t dp[2][K + 1][B];
    memset(dp[0], 0, sizeof dp[0]);
    dp[0][0][offset] = 1;
    for (int i = 0; i < N; ++i) {
        memset(dp[i & 1 ^ 1], 0, sizeof dp[i & 1 ^ 1]);
        for (int j = 0; j <= K; ++j) {
            for (int k = -offset; k <= offset; ++k) {
                int64_t val = dp[i & 1][j][k + offset];
                if (val == 0 || j + abs(k) > K) { continue; }
                if (a[i]) {
                    dp[i & 1 ^ 1][j + abs(k)][k + offset] += val;
                    dp[i & 1 ^ 1][j + abs(k)][k + offset] %= MOD;
                    if (k + offset + 1 < B) {
                        dp[i & 1 ^ 1][j + abs(k)][k + offset + 1] += val;
                        dp[i & 1 ^ 1][j + abs(k)][k + offset + 1] %= MOD;
                    }
                } else {
                    dp[i & 1 ^ 1][j + abs(k)][k + offset] += val;
                    dp[i & 1 ^ 1][j + abs(k)][k + offset] %= MOD;
                    if (k + offset - 1 >= 0) {
                        dp[i & 1 ^ 1][j + abs(k)][k + offset - 1] += val;
                        dp[i & 1 ^ 1][j + abs(k)][k + offset - 1] %= MOD;
                    }
                }
            }
        }
    }
    int64_t ans = 0;
    for (int j = K; j >= 0; j -= 2) {
        ans += dp[N & 1][j][offset];
        ans %= MOD;
    }
    cout << ans;
}
