/**
 *    author:  MaGnsi0
 *    created: 03.11.2024 16:09:54
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t K = 1e5 + 5, MOD = 1e9 + 7;

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
    vector<int64_t> F(K, 1), F_(K, 1);
    for (int i = 1; i < K; ++i) {
        F[i] = F[i - 1] * i % MOD;
        F_[i] = power(F[i], MOD - 2);
    }
    function<int64_t(int, int)> C = [&](int n, int k) {
        return F[n] * F_[k] % MOD * F_[n - k] % MOD;
    };
    int64_t n; cin >> n;
    int64_t k; cin >> k;
    int64_t ans = 0, prv_ways = 0;
    for (int64_t max_sim = 0; max_sim <= k; ++max_sim) {
        int64_t ways = (prv_ways + C(k, max_sim)) % MOD;
        int64_t cases = (power(ways, n - 1) % MOD - power(prv_ways, n - 1) + MOD) % MOD;
        ans += power(2, k) * max_sim % MOD * cases % MOD; ans %= MOD;
        prv_ways = ways;
    }
    ans *= power(power(2, n * k), MOD - 2); ans %= MOD;
    cout << ans;
}
