/**
 *    author:  MaGnsi0
 *    created: 20.05.2022 01:25:08
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 3, MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("galactic.in", "r", stdin);
    vector<int64_t> F(N, 1);
    for (int i = 2; i < N; ++i) {
        F[i] = (int64_t)i * F[i - 1];
        F[i] %= MOD;
    }
    vector<vector<int64_t>> dp(N, vector<int64_t>(N, -1));
    function<int64_t(int, int)> solve = [&](int x, int y) {
        if (y > x || x == 0) {
            return int64_t(0);
        }
        if (x == y || y == 1) {
            return int64_t(1);
        }
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        dp[x][y] = (y * solve(x - 1, y) + solve(x - 1, y - 1)) % MOD;
        return dp[x][y];
    };
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        cout << (F[k] * solve(n, k)) % MOD << "\n";
    }
}
