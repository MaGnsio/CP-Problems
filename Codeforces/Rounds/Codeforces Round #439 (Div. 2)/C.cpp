/**
 *    author:  MaGnsi0
 *    created: 19.05.2022 02:06:49
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 5e3 + 5, MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int64_t> F(N, 1);
    for (int i = 2; i < N; ++i) {
        F[i] = (int64_t)i * F[i - 1];
        F[i] %= MOD;
    }
    vector<vector<int64_t>> C(N, vector<int64_t>(N, 0));
    for (int i = 0; i < N; ++i) {
        C[i][0] = 1;
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j <= i; ++j) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            C[i][j] %= MOD;
        }
    }
    int64_t a, b, c;
    cin >> a >> b >> c;
    int64_t x = 0;
    for (int k = 0; k <= min(a, b); ++k) {
        x += ((C[a][k] * C[b][k]) % MOD * F[k]) % MOD;
        x %= MOD;
    }
    int64_t y = 0;
    for (int k = 0; k <= min(a, c); ++k) {
        y += ((C[a][k] * C[c][k]) % MOD * F[k]) % MOD;
        y %= MOD;
    }
    int64_t z = 0;
    for (int k = 0; k <= min(b, c); ++k) {
        z += ((C[b][k] * C[c][k]) % MOD * F[k]) % MOD;
        z %= MOD;
    }
    int64_t ans = ((x * y) % MOD * z) % MOD;
    cout << ans;
}
