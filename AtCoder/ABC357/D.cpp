/**
 *    author:  MaGnsi0
 *    created: 08.06.2024 15:29:49
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int64_t power(int64_t b, int64_t p) {
    int64_t res = 1; b %= MOD;
    while (p) {
        if (p & 1) { res = res * b % MOD; }
        b = b * b % MOD;
        p /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n; cin >> n;
    int64_t x = to_string(n).size();
    int64_t m = power(10, x);
    int64_t s = (power(m, n) + MOD - 1) % MOD * power(m + MOD - 1, MOD - 2) % MOD;
    int64_t ans = n % MOD * s % MOD;
    cout << ans;
}