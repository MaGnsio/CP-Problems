/**
 *    author:  MaGnsi0
 *    created: 04.06.2023 21:11:05
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

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
    int T;
    cin >> T;
    while (T--) {
        int64_t n, m, k;
        cin >> n >> m >> k;
        for (int i = 0; i < n; ++i) {
            int _; cin >> _;
        }
        vector<int64_t> mC(n, 1);
        for (int i = 1; i < n; ++i) {
            mC[i] = (m - i + 1) * power(i, MOD - 2) % MOD * mC[i - 1] % MOD;
        }
        int64_t ans = power(k, m);
        for (int i = 0; i < n; ++i) {
            ans -= mC[i] * power(k - 1, m - i) % MOD;
            ans += MOD;
            ans %= MOD;
        }
        cout << ans << "\n";
    }
}
