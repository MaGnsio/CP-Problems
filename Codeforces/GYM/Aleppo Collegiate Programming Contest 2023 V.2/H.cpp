/**
 *    author:  MaGnsi0
 *    created: 29.08.2023 15:15:52
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 1e6 + 6, MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<vector<int64_t>> dp(N, vector<int64_t>(3, -1));
    function<int64_t(int, int)> S1 = [&](int x, int y) {
        if (x == 0 && y == 0) { return int64_t(1); }
        if (x == 0 || y == 0) { return int64_t(0); }
        if (dp[x][y] != -1) { return dp[x][y]; }
        dp[x][y] = (int64_t(x - 1) * S1(x - 1, y) + S1(x - 1, y - 1)) % MOD;
        return dp[x][y];
    };
    vector<int64_t> F(N, 1);
    for (int i = 1; i < N; ++i) {
        F[i] = F[i - 1] * i % MOD;
    }
    int T;
    cin >> T;
    while (T--) {
        int64_t n;
        cin >> n;
        cout << (n * F[n] - S1(n + 1, 2) + MOD) % MOD << "\n";
    }
}
