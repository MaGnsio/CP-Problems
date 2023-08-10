/**
 *    author:  MaGnsi0
 *    created: 10.04.2023 23:35:54
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int64_t power(int64_t b, int64_t p) {
    int64_t ans = 1;
    while (p) {
        if (p & 1) { ans = ans * b % MOD; }
        b = b * b % MOD;
        p /= 2;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n;
    cin >> n;
    int64_t m = 2 * n + 10;
    vector<int64_t> F(m, 1), F_(m, 1), P2(m, 1);
    for (int64_t i = 1; i < m; ++i) {
        F[i] = i * F[i - 1];
        F[i] %= MOD;
        P2[i] = 2 * P2[i - 1];
        P2[i] %= MOD;
    }
    F_[m - 1] = power(F[m - 1], MOD - 2);
    for (int64_t i = m - 2; i >= 0; --i) {
        F_[i] = (i + 1) * F_[i + 1];
        F_[i] %= MOD;
    }
    function<int64_t(int64_t, int64_t)> C = [&](int64_t n, int64_t k) {
        if (k > n) { return int64_t(0); }
        return F[n] * F_[k] % MOD * F_[n - k] % MOD;
    };
    int64_t ans = 0;
    for (int64_t i = 1; i <= n + 1; ++i) {
        ans += C(n + 1, i) * C(n + 1, i);
        ans %= MOD;
    }
    cout << ans << "\n";
}
