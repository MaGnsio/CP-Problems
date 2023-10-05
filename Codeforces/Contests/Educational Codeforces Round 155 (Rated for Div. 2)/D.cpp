/**
 *    author:  MaGnsi0
 *    created: 24.09.2023 19:11:07
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t M = 31, MOD = 998244353;

int64_t S(int64_t L, int64_t R) {
    int64_t x = L * (L - 1) / 2;
    int64_t y = R * (R + 1) / 2;
    return (y - x) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> b(M, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < M; ++j) {
            b[j][i] += a[i] >> j & 1;
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < M; ++j) {
            b[j][i] += b[j][i - 1];
            b[j][i] %= 2;
        }
    }
    vector<vector<int64_t>> c(M, vector<int64_t>(n));
    vector<vector<int64_t>> d(M, vector<int64_t>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < M; ++j) {
            c[j][i] = b[j][i];
            d[j][i] = (b[j][i] ? i + 1 : 0);
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < M; ++j) {
            c[j][i] += c[j][i + 1];
            d[j][i] += d[j][i + 1];
        }
    }
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < M; ++j) {
            int p = (i ? b[j][i - 1] : 0);
            int64_t x = c[j][i], y = d[j][i];
            if (p) {
                x = n - i - x;
                y = S(i + 1, n) - y;
            }
            int64_t P2 = (1LL << j) % MOD;
            int64_t L = (y - x * i + MOD) % MOD;
            ans += P2 * L % MOD;
            ans %= MOD;
        }
    }
    cout << ans;
}
