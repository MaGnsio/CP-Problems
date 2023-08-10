/**
 *    author:  MaGnsi0
 *    created: 02.08.2023 20:26:07
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
    int64_t n, m, k;
    cin >> n >> m >> k;
    vector<int64_t> a(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }
    int64_t ans = power(k, n - 2 * a[m]);
    for (int i = 1; i <= m; ++i) {
        int64_t x = a[i] - a[i - 1];
        int64_t val = power(k, x);
        val *= power(k, x) + 1;
        val %= MOD;
        val *= power(2, MOD - 2);
        val %= MOD;
        ans *= val;
        ans %= MOD;
    }
    cout << ans;
}
