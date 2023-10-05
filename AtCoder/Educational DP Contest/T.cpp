/**
 *    author:  MaGnsi0
 *    created: 26.08.2023 16:03:43
**/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    string S; cin >> S;
    vector<vector<int>> dp(N + 1, vector<int>(N + 1));
    dp[1][1] = 1;
    for (int i = 2; i <= N; ++i) {
        for (int j = 1; j <= i; ++j) {
            int L, R;
            if (S[i - 2] == '<') {
                L = 1, R = j - 1;
            } else {
                L = j, R = i - 1; 
            }
            dp[i][j] += dp[i - 1][R] - dp[i - 1][L - 1];
            dp[i][j] %= MOD; dp[i][j] += MOD; dp[i][j] %= MOD;
            dp[i][j] += dp[i][j - 1]; dp[i][j] %= MOD;
        }
    }
    cout << dp[N][N];
}
