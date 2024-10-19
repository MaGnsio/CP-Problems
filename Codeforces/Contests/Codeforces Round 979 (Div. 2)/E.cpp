/**
 *    author:  MaGnsi0
 *    created: 19.10.2024 18:07:26
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 2e5 + 5, MOD = 998244353;

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
    vector<int64_t> F(N, 1), F_(N, 1), P2(N, 1);
    for (int i = 1; i < N; ++i) {
        F[i] = F[i - 1] * i % MOD;
        F_[i] = power(F[i], MOD - 2);
        P2[i] = P2[i - 1] * 2 % MOD;
    }
    function<int64_t(int, int)> C = [&](int n, int k) {
        if (n < k) { return int64_t(0); }
        return F[n] * F_[k] % MOD * F_[n - k] % MOD;
    };
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> f(n);
        for (int i = 0; i < n; ++i) {
            int x; cin >> x; f[x]++;
        }
        vector<vector<int64_t>> G(n);
        for (int i = 0; i < n; ++i) {
            G[i] = vector<int64_t>(f[i] + 1);
            for (int j = 0; j <= f[i]; ++j) {
                G[i][j] = C(f[i], j);
            }
            for (int j = f[i] - 1; j >= 0; --j) {
                G[i][j] += G[i][j + 1];
                G[i][j] %= MOD;
            }
        }
        int64_t ans = 0, limit = n, rem = n;
        vector<int64_t> total(n + 1, 1);
        for (int i = 0; i < n; ++i) {
            rem -= f[i];
            for (int j = 0; j <= f[i]; ++j) {
                total[j] *= G[i][j];
                total[j] %= MOD;
            }
            limit = min(limit, f[i]);
            for (int j = 0; j <= limit; ++j) {
                int64_t times = (total[j] - (j + 1 <= limit ? total[j + 1] : 0) + MOD) % MOD;
                ans += 1LL * j * times % MOD * P2[rem] % MOD;
                ans %= MOD;
            }
        }
        cout << ans << "\n";
    }
}
