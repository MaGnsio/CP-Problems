/**
 *    author:  MaGnsi0
 *    created: 06.02.2023 09:21:31
**/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7, N = 100;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("sets.in", "r", stdin);
    vector<vector<int>> dp(N, vector<int>(N, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= N / 2; ++i) {
        dp[i] = dp[i - 1];
        for (int j = 0; j < N; ++j) {
            if ((j ^ i) >= N) {
                continue;
            }
            dp[i][j ^ i] += dp[i - 1][j];
            dp[i][j ^ i] %= MOD;
        }
    }
    int xor_sum = 0;
    vector<int> ans(N / 2 + 1, 0);
    for (int i = 1; i <= N / 2; ++i) {
        xor_sum ^= i;
        for (int j = 0; j < N; ++j) {
            if ((xor_sum ^ j) < j) {
                ans[i] += dp[i][j];
                ans[i] %= MOD;
            }
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << ans[n] << "\n";
    }
}
