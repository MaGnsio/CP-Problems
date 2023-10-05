/**
 *    author:  MaGnsi0
 *    created: 27.08.2023 18:13:11
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7, N = 2e5 + 5;

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
        return F[n] * F_[k] % MOD * F_[n - k] % MOD;
    };
    function<int64_t(int, int, int)> G = [&](int n, int k, int max) {
        if (k == 0 || n < 0) { return int64_t(0); }
        int64_t ans = 0;
        for (int64_t i = 0; i <= k; ++i) {
            if (n < i * (max + 1)) { break; }
            int64_t val = C(k, i);
            val *= C((n - i * (max + 1)) + k - 1, k - 1);
            val %= MOD;
            if (i % 2 == 0) {
                ans += val;
                ans %= MOD;
            } else {
                ans -= val;
                ans += MOD;
                ans %= MOD;
            }
        }
        return ans;
    };
    int T;
    cin >> T;
    while (T--) {
        int n0, n1;
        cin >> n0 >> n1;
        int l0, r0;
        cin >> l0 >> r0;
        int l1, r1;
        cin >> l1 >> r1;
        int64_t ans = 0;
        for (int i = (n0 / r0); i <= (n0 / l0); ++i) {
            //010
            {
                int new_n0 = n0 - i * l0;
                int64_t val = G(new_n0, i, r0 - l0);
                int new_n1 = n1 - (i - 1) * l1;
                val *= G(new_n1, i - 1, r1 - l1);
                val %= MOD;
                ans += val;
                ans %= MOD;
            }
            //0101
            {
                int new_n0 = n0 - i * l0;
                int64_t val = G(new_n0, i, r0 - l0);
                int new_n1 = n1 - i * l1;
                val *= G(new_n1, i, r1 - l1);
                val %= MOD;
                ans += 2 * val;
                ans %= MOD;
            }
            //101
            {
                int new_n0 = n0 - i * l0;
                int64_t val = G(new_n0, i, r0 - l0);
                int new_n1 = n1 - (i + 1) * l1;
                val *= G(new_n1, i + 1, r1 - l1);
                val %= MOD;
                ans += val;
                ans %= MOD;
            }
        }
        cout << ans << "\n";
    }
}
