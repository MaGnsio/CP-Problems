/**
 *    author:  MaGnsi0
 *    created: 06/09/2021 20:17:22
**/
#include <bits/stdc++.h>
using namespace std;

const long long OO = LLONG_MAX;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<string> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
        reverse(b[i].begin(), b[i].end());
    }
    vector<vector<long long>> dp(n, vector<long long>(2, OO));
    dp[0][0] = 0, dp[0][1] = v[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] >= a[i - 1] && dp[i - 1][0] != OO) {
            dp[i][0] = dp[i - 1][0];
        }
        if (a[i] >= b[i - 1] && dp[i - 1][1] != OO) {
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        }
        if (b[i] >= a[i - 1] && dp[i - 1][0] != OO) {
            dp[i][1] = dp[i - 1][0] + v[i];
        }
        if (b[i] >= b[i - 1] && dp[i - 1][1] != OO) {
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + v[i]);
        }
    }
    long long res = min(dp[n - 1][0], dp[n - 1][1]);
    cout << (res == OO ? -1 : res);
}
