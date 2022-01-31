/**
 *    author:  MaGnsi0
 *    created: 05.01.2022 20:49:35
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = (n & 1 ? a[i] : 0);
    }
    for (int k = 1; k < n; ++k) {
        for (int i = 0; i + k < n; ++i) {
            int j = i + k;
            if ((n - (j - i + 1)) % 2 == 0) {
                dp[i][j] = max(a[i] + dp[i + 1][j], dp[i][j - 1] + a[j]);
            } else {
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[0][n - 1];
}
