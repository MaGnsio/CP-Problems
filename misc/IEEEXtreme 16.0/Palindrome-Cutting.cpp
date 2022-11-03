/**
 *    author:  MaGnsi0
 *    created: 22.10.2022 07:12:08
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int64_t power(int64_t b, int64_t p) {
    int64_t res = 1;
    while (p) {
        if (p & 1) { res = res * b % MOD; }
        b = b * b % MOD;
        p >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, m;
    cin >> n >> m;
    int64_t ans = 0;
    for (int i = 1; i <= n / 2; ++i) {
        ans += power(m, i) % MOD;
        ans %= MOD;
    }
    cout << ans;
}
