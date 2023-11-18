/**
 *    author:  MaGnsi0
 *    created: 23.09.2023 11:38:34
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

int64_t Trees(int n) {
    return power(n, n - 2);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if (n & 1) {
        cout << 0;
        return 0;
    }
    vector<int64_t> F(n + 1, 1), F_(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        F[i] = F[i - 1] * i % MOD;
        F_[i] = power(F[i], MOD - 2);
    }
    function<int64_t(int, int)> C = [&](int x, int y) {
        return F[x] * F_[y] % MOD * F_[x - y] % MOD;
    };
    int64_t ans = power(4, n / 2 - 1) * Trees(n / 2) % MOD;
    ans = ans * F_[n / 2] % MOD;
    while (n) {
        ans = ans * C(n, 2) % MOD;
        n -= 2;
    }
    cout << ans;
}
