/**
 *    author:  MaGnsi0
 *    created: 13.02.2024 18:28:10
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 4e6 + 6, MOD = 998244353;

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
    vector<int64_t> F(N, 1), F_(N, 1);
    for (int i = 1; i < N; ++i) {
        F[i] = F[i - 1] * i % MOD;
        F_[i] = power(F[i], MOD - 2);
    }
    function<int64_t(int, int)> C = [&](int n, int k) {
        if (n < k) { return int64_t(0); }
        return F[n] * F_[n - k] % MOD * F_[k] % MOD;
    };
    int T; cin >> T;
    while (T--) {
        vector<int> c(4);
        for (int i = 0; i < 4; ++i) {
            cin >> c[i];
        }
        if (abs(c[0] - c[1]) > 1) {
            cout << 0 << "\n";
            continue;
        }
        if (c[0] + c[1] + c[2] + c[3] == 0) {
            cout << 1 << "\n";
            continue;
        }
        int64_t ans = 0;
        if (c[1] >= c[0]) {
            for (int left3 = 1; left3 <= c[3]; ++left3) {
                int64_t ways1 = (c[0] ? C(c[3] - left3 + c[0] - 1, c[3] - left3) : (left3 == c[3] ? 1 : 0));
                int64_t ways2 = (c[2] + c[1] ? C(c[2] + c[1] - 1, c[2]) : 1);
                ans += ways1 * ways2 % MOD;
                ans %= MOD;
            }
        }
        if (c[0] >= c[1]) {
            for (int left2 = 1; left2 <= c[2]; ++left2) {
                int64_t ways1 = (c[3] + c[0] ? C(c[3] + c[0] - 1, c[3]) : 1);
                int64_t ways2 = (c[1] ? C(c[2] - left2 + c[1] - 1, c[2] - left2) : (left2 == c[2] ? 1 : 0));
                ans += ways1 * ways2 % MOD;
                ans %= MOD;
            }
        }
        int64_t ways1 = (c[3] + c[0] ? C(c[3] + c[0] - 1, c[3]) : 1);
        int64_t ways2 = (c[2] + c[1] ? C(c[2] + c[1] - 1, c[2]) : 1);
        ans += (c[0] == c[1] ? 2LL : 1LL) * ways1 * ways2 % MOD;
        ans %= MOD;
        cout << ans << "\n";
    }
}
