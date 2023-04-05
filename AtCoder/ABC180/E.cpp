/**
 *    author:  MaGnsi0
 *    created: 09.11.2022 20:49:21
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e12;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int64_t> X(n), Y(n), Z(n);
    for (int i = 0; i < n; ++i) {
        cin >> X[i] >> Y[i] >> Z[i];
    }
    function<int64_t(int, int)> D = [&](int i, int j) {
        return abs(X[i] - X[j]) + abs(Y[i] - Y[j]) + max(Z[j] - Z[i], int64_t(0));
    };
    vector<vector<int64_t>> dp(1 << n, vector<int64_t>(n, -1));
    function<int64_t(int, int)> solve = [&](int mask, int prev) {
        if (__builtin_popcount(mask) == n) {
            return D(prev, 0);
        }
        if (dp[mask][prev] != -1) {
            return dp[mask][prev];
        }
        dp[mask][prev] = OO;
        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                continue;
            }
            dp[mask][prev] = min(dp[mask][prev], D(prev, i) + solve(mask | (1 << i), i));
        }
        return dp[mask][prev];
    };
    cout << solve(1, 0);
}
