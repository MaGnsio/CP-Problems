/**
 *    author:  MaGnsi0
 *    created: 07.07.2024 19:08:36
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 1e6, MOD = 1e9 + 7;

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
    function<int64_t(int, int)> C = [&](int n, int k) {
        if (k > n) { return int64_t(0); }
        return F[n] * F_[k] % MOD * F_[n - k] % MOD;
    };
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        int m = n - k;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int64_t X = 0, Y = 0;
        for (int i = 0; i < m; i += 2) {
            X += C(m - 1, i) * F[i] % MOD * F[m - i - 1] % MOD;
            X %= MOD;
        }
        for (int i = 0; i <= m; i += 2) {
            Y += C(m, i) * F[i] % MOD * F[m - i] % MOD;
            Y %= MOD;
        }
        X = X * C(n, k) % MOD * F[k] % MOD * F_[n] % MOD;
        Y = Y * C(n, k - 1) % MOD * F[k - 1] % MOD * F_[n] % MOD;
        int64_t ealice = 0;
        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                ealice = (ealice + X * a[i]) % MOD;
            } else {
                ealice = (ealice + Y * a[i]) % MOD;
            }
        }
        int64_t ebob = 0;
        for (int i = 0; i < n; ++i) {
            ebob = (ebob + a[i]) % MOD;
        }
        ebob = (ebob - ealice + MOD) % MOD;
        cout << ealice << " " << ebob << "\n";
    }
}
