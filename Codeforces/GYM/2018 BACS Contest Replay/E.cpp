/**
 *    author:  MaGnsi0
 *    created: 20.10.2023 16:30:01
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 1e7 + 7, MOD = 1e9 + 7;

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
    }
    F_[N - 1] = power(F[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; --i) {
        F_[i] = F_[i + 1] * (i + 1) % MOD;
    }
    function<int64_t(int64_t, int64_t)> C = [&](int64_t n, int64_t k) {
        if (n < k) { return int64_t(0); }
        return F[n] * F_[k] % MOD * F_[n - k] % MOD;
    };
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        int64_t m; cin >> m;
        int64_t k; cin >> k;
        int64_t ans = C(n, k) * power(m, k) % MOD;
        cout << ans << "\n";
    }
}