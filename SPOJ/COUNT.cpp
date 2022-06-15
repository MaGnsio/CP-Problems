/**
 *    author:  MaGnsi0
 *    created: 18.05.2022 22:08:23
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5, MOD = 1988;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<vector<int>> dp(N, vector<int>(N, -1));
    function<int(int, int)> solve = [&](int n, int k) {
        if (n == 0) {
            return 1;
        }
        if (k == 0 || n < 0) {
            return 0;
        }
        if (dp[n][k] != -1) {
            return dp[n][k];
        }
        //it's like filling trucks one on each truck then drop one truck from the next filling process or not.
        dp[n][k] = (solve(n, k - 1) + solve(n - k, k)) % MOD;
        return dp[n][k];
    };
    int n, k;
    while ((cin >> n >> k) && n && k) {
        //the first filling process is a must, as there can't be any empty truck.
        cout << solve(n - k, k) << "\n";
    }
}
