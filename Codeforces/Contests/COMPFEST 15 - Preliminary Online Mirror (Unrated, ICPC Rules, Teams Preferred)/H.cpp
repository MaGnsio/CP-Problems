/**
 *    author:  MaGnsi0
 *    created: 03.09.2023 16:49:54
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

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
    int n, k;
    cin >> n >> k;
    int N = max(n, k) + 10;
    vector<int64_t> P2(N, 1), F(N, 1), F_(N, 1);
    for (int i = 1; i < N; ++i) {
        F[i] = F[i - 1] * i % MOD;
        F_[i] = power(F[i], MOD - 2);
        P2[i] = P2[i - 1] * 2;
        P2[i] %= MOD;
    }
    function<int64_t(int, int)> C = [&](int x, int y) {
        if (y > x) { return int64_t(0); }
        return F[x] * F_[y] % MOD * F_[x - y] % MOD;
    };
    int64_t ans = 1;
    for (int i = 0; i < n; ++i) {
        if (n - i > k) { continue; }
        int64_t must_have = k - (n - i) + 1;
        int64_t val = (power(n - i + 1, must_have) - power(n - i, must_have) + MOD) % MOD;
        val *= F[k - must_have + 1] % MOD;
        val %= MOD;
        val *= F[n - i];
        val %= MOD;
        val *= C(n, i);
        val %= MOD;
        ans += val;
        ans %= MOD;
    }
    cout << ans;
}
