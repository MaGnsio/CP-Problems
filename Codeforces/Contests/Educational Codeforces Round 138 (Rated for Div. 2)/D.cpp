/**
 *    author:  MaGnsi0
 *    created: 20.10.2022 17:16:40
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 3e5 + 5, MOD = 998244353;

int64_t power(int64_t b, int64_t p) {
    int64_t res = 1;
    b %= MOD;
    while (p) {
        if (p & 1) { res = res * b % MOD; }
        b = b * b % MOD;
        p >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<bool> is_prime(N, true);
    for (int i = 2; i < N; ++i) {
        if (is_prime[i]) {
            for (int j = 2 * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    int64_t n, m, X = 1;
    cin >> n >> m;
    vector<int64_t> cnt(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (is_prime[i]) {
            X *= i;
        }
        if (X > m) {
            break;
        }
        cnt[i] = m / X;
        cnt[i] %= MOD;
    }
    int64_t ans = 0, cur = 1;
    for (int64_t i = 1; i <= n; ++i) {
        cur *= cnt[i];
        cur %= MOD;
        ans += power(m, i);
        ans %= MOD;
        ans -= cur;
        ans += MOD;
        ans %= MOD;
    }
    cout << ans;
}
