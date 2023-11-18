/**
 *    author:  MaGnsi0
 *    created: 13.10.2023 15:55:05
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 2e5, MOD = 1e9 + 7;

int64_t power(int64_t b, int64_t p) {
    int64_t res = 1;
    while (p) {
        if (p & 1) { res = res * b % MOD; }
        b = b * b % MOD;
        p /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int64_t> F(N, 1), F_(N, 1);
    for (int i = 1; i < N; ++i) {
        F[i] = F[i - 1] * i % MOD;
        F_[i] = power(F[i], MOD - 2);
    }
    function<int64_t(int64_t, int64_t)> C = [&](int64_t n, int64_t k) {
        if (k < 0) { return int64_t(0); }
        if (n < k) { return int64_t(0); }
        return F[n] * F_[k] % MOD * F_[n - k] % MOD;
    };
    int T;
    cin >> T;
    while (T--) {
        int64_t n, k;
        cin >> n >> k;
        int64_t ans = 1, p = 1;
        for (int64_t lights = 1; lights <= n; ++lights) {
            int64_t freeLights = n - k * (lights - 1) - 1;
            p = p * power(n - lights + 1, MOD - 2) % MOD;
            int64_t ways = p * F[lights] % MOD * C(freeLights + lights, freeLights) % MOD;
            ans += ways % MOD;
            ans %= MOD;
        }
        cout << ans << "\n";
    }
}
