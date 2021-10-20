/**
 *    author:  MaGnsi0
 *    created: 14.10.2021 14:31:22
**/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<vector<int>> dp(n, vector<int>(3003, 0));
    for (int i = a[0]; i <= b[0]; ++i) {
        dp[0][i] = 1;
    }
    for (int i = 1; i < 3003; ++i) {
        dp[0][i] += dp[0][i - 1];
        dp[0][i] %= MOD;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = a[i]; j <= b[i]; ++j) {
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= MOD;
        }
        for (int j = 1; j < 3003; ++j) {
            dp[i][j] += dp[i][j - 1];
            dp[i][j] %= MOD;
        }
    }
    cout << dp[n - 1][3002];
}
