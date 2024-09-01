/**
 *    author:  MaGnsi0
 *    created: 01.09.2024 18:03:22
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

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
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        int64_t sum = 0;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; sum += a[i]; sum %= MOD;
        }
        int64_t ans = 0, total = n * (n - 1) % MOD * power(2, MOD - 2) % MOD;
        for (int i = 0; i < n; ++i) {
            sum = (sum - a[i] + MOD) % MOD;
            ans += a[i] * sum % MOD;
            ans %= MOD;
        }
        ans = ans * power(total, MOD - 2) % MOD;
        cout << ans << "\n";
    }
}
