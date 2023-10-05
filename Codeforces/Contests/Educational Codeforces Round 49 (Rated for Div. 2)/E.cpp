/**
 *    author:  MaGnsi0
 *    created: 01.08.2023 18:21:50
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 505, MOD = 998244353;

int64_t power(int64_t b, int64_t p) {
    int64_t res = 1;
    while (p) {
        if (p & 1) { res = res * b % MOD; }
        b = b * b % MOD;
        p /= 2;
    }
    return res;
}

int n, k, m, K;
int64_t ans, dp1[N][N][2], dp2[N][N];

int64_t solve1(int i, int j, int y) {
    if (i == n) { return int64_t(y); }
    int64_t& res = dp1[i][j][y];
    if (res != -1) { return res; }
    res = solve1(i + 1, 1, y || (m == 1)); 
    if (j + 1 <= m) {
        res += solve1(i + 1, j + 1, y || (j + 1 == m));
        while (res >= MOD) { res -= MOD; }
    }
    return res;
};

int64_t solve2(int i, int j) {
    if (i == n) { return int64_t(1); }
    int64_t& res = dp2[i][j];
    if (res != -1) { return res; }
    res = solve2(i + 1, 1);
    if (m * (j + 1) < k) {
        res += solve2(i + 1, j + 1);
        while (res >= MOD) { res -= MOD; }
    }
    return res;
};

void reset(int x) {
    m = x;
    memset(dp1, -1, sizeof dp1);
    memset(dp2, -1, sizeof dp2);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k; K = min(k, n + 1);
    for (int i = 1; i < K; ++i) {
        reset(i);
        ans += solve1(0, 0, 0) * solve2(0, 0) % MOD;
        ans %= MOD;
    }
    cout << power(2, MOD - 2) * ans % MOD;
}
