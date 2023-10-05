/**
 *    author:  MaGnsi0
 *    created: 07.01.2023 20:14:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t N, MOD;
    cin >> N >> MOD;
    function<int64_t(int64_t, int64_t)> power = [&](int64_t b, int64_t p) {
        int64_t ans = 1;
        while (p) {
            if (p & 1) { ans = ans * b % MOD; }
            b = b * b % MOD;
            p >>= 1;
        }
        return ans;
    };
    vector<int64_t> F(3 * N + 3, 1), invF(3 * N + 3, 1);
    for (int i = 1; i < 3 * N + 3; ++i) {
        F[i] = F[i - 1] * i;
        F[i] %= MOD;
    }
    invF[3 * N + 2] = power(F[3 * N + 2], MOD - 2);
    for (int i = 3 * N + 2; i > 0; --i) {
        invF[i - 1] = invF[i] * i;
        invF[i - 1] %= MOD;
    }
    function<int64_t(int64_t, int64_t)> C = [&](int64_t n, int64_t k) {
        if (n < k) { return int64_t(0); }
        return F[n] * invF[k] % MOD * invF[n - k] % MOD;
    };
    vector<int64_t> cnt(4);
    //count of permutations that have F = 0
    cnt[0] = 1;
    //count of permutations that have F = 1
    cnt[1] = 2 * F[2 * N];
    cnt[1] %= MOD;
    cnt[1] -= F[N];
    cnt[1] += MOD;
    cnt[1] %= MOD;
    cnt[1] -= cnt[0];
    cnt[1] += MOD;
    cnt[1] %= MOD;
    //count of permutations that have F = 2
    cnt[2] = 2 * C(2 * N, N);
    cnt[2] %= MOD;
    cnt[2] *= F[N];
    cnt[2] %= MOD;
    cnt[2] *= F[2 * N];
    cnt[2] %= MOD;
    for (int i = 0; i <= N; ++i) {
        //i of the n smallest numbers are in the first n postions
        int64_t val = C(N, i) * C(N, N - i);
        val %= MOD;
        val *= C(2 * N - i, N);
        val %= MOD;
        val *= power(F[N], 3);
        val %= MOD;
        cnt[2] -= val;
        cnt[2] += MOD;
        cnt[2] %= MOD;
    }
    cnt[2] -= cnt[1];
    cnt[2] += MOD;
    cnt[2] %= MOD;
    cnt[2] -= cnt[0];
    cnt[2] += MOD;
    cnt[2] %= MOD;
    //count of permutations that have F = 3
    cnt[3] = F[3 * N];
    cnt[3] -= cnt[2];
    cnt[3] += MOD;
    cnt[3] %= MOD;
    cnt[3] -= cnt[1];
    cnt[3] += MOD;
    cnt[3] %= MOD;
    cnt[3] -= cnt[0];
    cnt[3] += MOD;
    cnt[3] %= MOD;
    int64_t ans = (0 * cnt[0] + 1 * cnt[1] + 2 * cnt[2] + 3 * cnt[3]) % MOD;
    cout << ans;
}
