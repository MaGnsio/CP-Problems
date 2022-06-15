/**
 *    author:  MaGnsi0
 *    created: 26.05.2022 19:16:02
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, K;
    cin >> N >> K;
    vector<vector<double>> dp(N + 1, vector<double>(K + 1, -1));
    function<double(int, int)> solve = [&](int n, int k) {
        if (k == 0) {
            return double(N - n);
        }
        if (dp[n][k] != -1) {
            return dp[n][k];
        }
        dp[n][k] = 0.5 * solve((n > 1 || k == 1 ? n - 1 : n), k - 1) + 0.5 * solve(n, k - 1);
        return dp[n][k];
    };
    cout << fixed << setprecision(9) << solve(N, K);
}
