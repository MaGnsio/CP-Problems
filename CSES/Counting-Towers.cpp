/**
 *    author:  MaGnsi0
 *    created: 02.01.2022 14:43:03
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<vector<int>> dp(N, vector<int>(2));
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i < N; ++i) {
        dp[i][0] = (4LL * dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = (2LL * dp[i - 1][1] + dp[i - 1][0]) % MOD;
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % MOD << "\n";
    }
}
