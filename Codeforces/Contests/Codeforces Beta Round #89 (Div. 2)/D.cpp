/**
 *    author:  MaGnsi0
 *    created: 08.09.2022 19:55:22
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 105, M = 15, MOD = 1e8;

int N1, N2, K1, K2;

int64_t dp[N][N][M][M];

int64_t solve(int n1, int n2, int k1, int k2) {
    int64_t& res = dp[n1][n2][k1][k2];
    if (res != -1) {
        return res;
    }
    if (n1 == 0 && n2 == 0) {
        return res = 1;
    }
    res = 0;
    if (k1 + 1 <= K1 && n1) {
        res += solve(n1 - 1, n2, k1 + 1, 0);
        res %= MOD;
    }
    if (k2 + 1 <= K2 && n2) {
        res += solve(n1, n2 - 1, 0, k2 + 1);
        res %= MOD;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N1 >> N2 >> K1 >> K2;
    memset(dp, -1, sizeof dp);
    cout << solve(N1, N2, 0, 0);
}
