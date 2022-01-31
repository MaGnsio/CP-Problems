/**
 *    author:  MaGnsi0
 *    created: 24.12.2021 14:55:41
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e8;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> s(n);
    s[0] = a[0];
    for (int i = 1; i < n; ++i) {
        s[i] = s[i - 1] + a[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, OO));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 0;
    }
    for (int k = 1; k < n; ++k) {
        for (int i = 0; i + k < n; ++i) {
            for (int j = i; j < i + k; ++j) {
                dp[i][i + k] = min(dp[i][i + k], dp[i][j] + dp[j + 1][i + k] + (s[i + k] - (i ? s[i - 1] : 0)));
            }
        }
    }
    cout << dp[0][n - 1];
}
