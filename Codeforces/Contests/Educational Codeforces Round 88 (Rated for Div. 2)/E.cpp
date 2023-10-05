/**
 *    author:  MaGnsi0
 *    created: 19.06.2023 18:30:04
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

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
    int n, k;
    cin >> n >> k;
    vector<int64_t> F(n + 1, 1), invF(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        F[i] = F[i - 1] * i % MOD;
        invF[i] = power(F[i], MOD - 2);
    }
    function<int64_t(int, int)> C = [&](int x, int y) {
        if (x < y) { return int64_t(0); }
        return F[x] * invF[y] % MOD * invF[x - y] % MOD;
    };
    int64_t ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += C((n / i) - 1, k - 1);
        ans %= MOD;
    }
    cout << ans;
}
