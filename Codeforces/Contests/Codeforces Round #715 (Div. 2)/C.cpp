/**
 *    author:  MaGnsi0
 *    created: 01.03.2022 20:06:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j + i < n; ++j) {
            dp[j][j + i] = a[j + i] - a[j] + min(dp[j][j + i - 1], dp[j + 1][j + i]);
        }
    }
    cout << dp[0][n - 1];
}
