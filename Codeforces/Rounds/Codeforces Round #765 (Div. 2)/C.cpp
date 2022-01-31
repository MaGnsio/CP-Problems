/**
 *    author:  MaGnsi0
 *    created: 12.01.2022 13:57:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, l, k;
    cin >> n >> l >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<long long> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<vector<long long>> dp(n, vector<long long>(k + 1, -1));
    function<long long(int, int)> solve = [&](int x, int y) {
        if (x == n) {
            return 0LL;
        }
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        dp[x][y] = LLONG_MAX;
        for (int i = x, j = y; i < n && j <= k; ++i, ++j) {
            dp[x][y] = min(dp[x][y], solve(i + 1, j) + b[x] * ((i + 1 == n ? 1LL * l : a[i + 1]) - a[x]));
        }
        return dp[x][y];
    };
    cout << solve(0, 0);
}
