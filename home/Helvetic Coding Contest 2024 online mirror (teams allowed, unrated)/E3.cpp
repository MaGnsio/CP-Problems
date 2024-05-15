/**
 *    author:  MaGnsi0
 *    created: 13.05.2024 22:54:11
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
    int n; cin >> n;
    int m; cin >> m;
    vector<int64_t> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int64_t all = 0;
    for (int i = 0; i < n; ++i) {
        all += 2 * a[i] * b[i] % MOD;
        all %= MOD;
        all += a[i] * a[i] % MOD;
        all %= MOD;
    }
    int64_t ans = power(all, m - 1);
    cout << ans;
}
