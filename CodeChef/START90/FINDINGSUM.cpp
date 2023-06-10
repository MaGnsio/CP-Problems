/**
 *    author:  MaGnsi0
 *    created: 18.05.2023 15:27:22
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 2e5 + 5, MOD = 998244353;

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
    vector<int64_t> F(N, 1), inv_F(N, 1), P2(N, 1);
    for (int i = 1; i < N; ++i) {
        F[i] = i * F[i - 1] % MOD;
        inv_F[i] = power(F[i], MOD - 2);
        P2[i] = 2 * P2[i - 1] % MOD;
    }
    function<int64_t(int, int)> C = [&](int n, int k) {
        if (k > n) { return int64_t(0); }
        return F[n] * inv_F[k] % MOD * inv_F[n - k] % MOD;
    };
    int T;
    cin >> T;
    while (T--) {
        int64_t n, m;
        cin >> n >> m;
        int64_t ans = 0;
        for (int64_t k = 0; k <= m; ++k) {
            int64_t add = 0;
            for (int64_t j = 0; j <= min(n, m - k); ++j) {
                add += C(n, j) * C(j + (m - k - j) - 1, (m - k - j)) % MOD * C((n - j) + (m - k) - 1, m - k) % MOD;
                add %= MOD;
            }
            add *= 4 * C(n + k - 1, k);
            add %= MOD;
            add *= (m - k);
            add %= MOD;
            add *= (m - k);
            add %= MOD;
            ans += add;
            ans %= MOD;
        }
        cout << ans << "\n";
    }
}
