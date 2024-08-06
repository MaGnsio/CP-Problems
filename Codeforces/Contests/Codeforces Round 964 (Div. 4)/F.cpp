/**
 *    author:  MaGnsi0
 *    created: 06.08.2024 18:15:16
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 2e5 + 5, MOD = 1e9 + 7;

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
        int ones = 0, zeros = 0;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            ones += x == 1;
            zeros += x == 0;
        }
        int64_t ans = 0;
        for (int j = (k + 1) / 2; j <= k; ++j) {
            ans += C(ones, j) * C(zeros, k - j) % MOD;
            ans %= MOD;
        }
        cout << ans << "\n";
    }

}
