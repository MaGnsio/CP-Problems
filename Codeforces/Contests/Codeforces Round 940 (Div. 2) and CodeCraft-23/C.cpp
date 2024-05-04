/**
 *    author:  MaGnsi0
 *    created: 22.04.2024 10:25:00
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5, MOD = 1e9 + 7;

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
    vector<int64_t> F(N, 1), F_(N, 1);
    for (int i = 1; i < N; ++i) {
        F[i] = i * F[i - 1] % MOD;
        F_[i] = power(F[i], MOD - 2);
    }
    function<int64_t(int, int)> C = [&](int n, int k) {
        if (n < k) { return int64_t(0); }
        return F[n] * F_[k] % MOD * F_[n - k] % MOD;
    };
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        for (int i = 0; i < k; ++i) {
            int x; cin >> x;
            int y; cin >> y;
            n -= (x != y) + 1;
        }
        int64_t ans = 0;
        for (int same = 0; same <= n; ++same) {
            int not_same = n - same;
            if (not_same & 1) { continue; }
            int64_t val = C(n, same) * C(not_same, not_same / 2) % MOD * F[not_same / 2] % MOD;
            ans = (ans + val) % MOD;
        }
        cout << ans << "\n";
    }
}
