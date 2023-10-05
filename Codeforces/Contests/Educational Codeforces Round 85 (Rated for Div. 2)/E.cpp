/**
 *    author:  MaGnsi0
 *    created: 05.08.2023 15:53:24
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t M = 200, MOD = 998244353;

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
    vector<int64_t> F(M, 1), F_(M, 1);
    for (int i = 1; i < M; ++i) {
        F[i] = F[i - 1] * i % MOD;
        F_[i] = power(F[i], MOD - 2);
    }
    function<int64_t(int, int)> C = [&](int n, int k) {
        return F[n] * F_[k] % MOD * F_[n - k] % MOD;
    };
    int64_t N;
    cin >> N;
    vector<int64_t> primes;
    for (int64_t i = 2; i * i <= N; ++i) {
        while (N % i == 0) {
            primes.push_back(i);
            N /= i;
        }
    }
    if (N > 1) { primes.push_back(N); }
    int Q;
    cin >> Q;
    while (Q--) {
        int64_t x, y;
        cin >> x >> y;
        int64_t g = __gcd(x, y);
        x /= g, y /= g;
        int m1 = 0, m2 = 0;
        map<int64_t, int> mp1, mp2;
        for (int64_t prime : primes) {
            if (x % prime == 0) {
                mp1[prime]++;
                x /= prime;
                m1++;
            }
            if (y % prime == 0) {
                mp2[prime]++;
                y /= prime;
                m2++;
            }
        }
        int64_t ans1 = 1, ans2 = 1;
        for (auto [_, k] : mp1) {
            ans1 *= C(m1, k);
            ans1 %= MOD;
            m1 -= k;
        }
        for (auto [_, k] : mp2) {
            ans2 *= C(m2, k);
            ans2 %= MOD;
            m2 -= k;
        }
        cout << ans1 * ans2 % MOD << "\n";
    }
}
