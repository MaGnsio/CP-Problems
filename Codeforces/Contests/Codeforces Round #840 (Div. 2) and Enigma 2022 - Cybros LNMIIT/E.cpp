/**
 *    author:  MaGnsi0
 *    created: 20.12.2022 21:17:19
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e10;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n;
    cin >> n;
    vector<int64_t> dp(n + 1, -1);
    function<int64_t(int)> solve = [&](int j) {
        if (j == 0) {
            return int64_t(0);
        }
        if (dp[j] != -1) {
            return dp[j];
        }
        dp[j] = OO;
        for (int i = 1; i * (i + 1) / 2 <= j; ++i) {
            dp[j] = min(dp[j], solve(j - (i * (i + 1) / 2)) + i + 1);
        }
        return dp[j];
    };
    cout << solve(n) << " " << solve(n) * (solve(n) - 1) / 2 - n;
}
