/**
 *    author:  MaGnsi0
 *    created: 27.01.2024 17:21:26
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 4e5, MOD = 1e9 + 7;

int64_t power(int64_t b, int64_t p) {
    if (b == 0) { return (p ? 0 : 1); }
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
    const int64_t Half = power(2, MOD - 2);
    vector<int64_t> F(N, 1), F_(N, 1);
    for (int i = 1; i < N; ++i) {
        F[i] = F[i - 1] * i % MOD;
        F_[i] = power(F[i], MOD - 2);
    }
    function<int64_t(int, int)> C = [&](int n, int k) {
        if (k > n) { return int64_t(0); }
        return F[n] * F_[k] % MOD * F_[n - k] % MOD;
    };
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        int64_t m; cin >> m;
        int64_t k; cin >> k;
        vector<int64_t> f(m);
        for (int i = 0; i < m; ++i) {
            int _; cin >> _; cin >> _;
            cin >> f[i]; f[i] %= MOD;
        }
        int64_t P = 2LL * power(n, MOD - 2) % MOD * power(n - 1, MOD - 2) % MOD;
        int64_t X = 0, Y = 0;
        for (int64_t i = 1; i <= k; ++i) {
            int64_t totalP = power(P, i) * power((1 - P + MOD) % MOD, k - i) % MOD;
            X += i * totalP % MOD * C(k, i) % MOD; X %= MOD;
        }
        for (int64_t i = 0; i <= k; ++i) {
            int64_t totalP = power(P, i) * power((1 - P + MOD) % MOD, k - i) % MOD;
            Y += totalP % MOD * i % MOD * (i - 1) % MOD * Half % MOD * C(k, i) % MOD;
            Y %= MOD;
        }
        int64_t ans = 0;
        for (int i = 0; i < m; ++i) {
            ans += f[i] * X % MOD;
            ans %= MOD;
            ans += Y;
            ans %= MOD;
        }
        cout << ans << "\n";
    }
}
