/**
 *    author:  MaGnsi0
 *    created: 15.10.2024 20:46:21
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 505, MOD = 998244353;

int n, m, f[N][N][N], g[N][N];

int F(int i, int j, int k) {
    if (j == 0) { return 1; }
    if (i == m) { return 0; }
    if (f[i][j][k] != -1) { return f[i][j][k]; }
    f[i][j][k] = 0;
    if (j) {
        f[i][j][k] += F(i + 1, j - 1, k + 1);
        f[i][j][k] %= MOD;
    }
    if (k) {
        f[i][j][k] += F(i + 1, j, k - 1);
        f[i][j][k] %= MOD;
    }
    return f[i][j][k];
}

int64_t G(int i, int j) {
    if (i == n) { return j == 0; }
    if (g[i][j] != -1) { return g[i][j]; }
    g[i][j] = 0;
    for (int j_ = 0; j_ <= j; ++j_) {
        if ((m - j_) & 1) { continue; }
        int need = (m - j_) / 2;
        g[i][j] += 1LL * G(i + 1, j - j_) * F(0, need, j_) % MOD;
        g[i][j] %= MOD;
    }
    return g[i][j];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(f, -1, sizeof f);
    memset(g, -1, sizeof g);
    cin >> n >> m;
    int64_t ans = 0;
    for (int x = 0; x <= m / 2; ++x) {
        ans += 1LL * F(0, (m / 2) + x, 0) * G(1, 2 * x) % MOD;
        ans %= MOD;
    }
    cout << ans;
}
