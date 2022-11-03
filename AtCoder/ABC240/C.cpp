/**
 *    author:  MaGnsi0
 *    created: 23.02.2022 01:32:48
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(x + 1, false));
    dp[0][0] = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= x; ++j) {
            if (j + a[i] <= x) {
                dp[i + 1][j + a[i]] = (dp[i + 1][j + a[i]] || dp[i][j]);
            }
            if (j + b[i] <= x) {
                dp[i + 1][j + b[i]] = (dp[i + 1][j + b[i]] || dp[i][j]);
            }
        }
    }
    cout << (dp[n][x] ? "Yes" : "No");
}
