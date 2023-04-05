/**
 *    author:  MaGnsi0
 *    created: 21.01.2023 05:26:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, MOD;
    cin >> n >> MOD;
    int64_t sum = 0;
    for (int i = 0; i < n; ++i) {
        int64_t x;
        cin >> x;
        sum += x;
        sum %= MOD;
    }
    if (sum == 0) {
        cout << "0 \n0 0";
        return 0;
    }
    int64_t nMOD = n % MOD;
    nMOD = gcd(nMOD, MOD);
    int64_t s0 = -1, min_sum0 = (sum + nMOD * ((MOD - sum + nMOD - 1) / nMOD)) % MOD;
    for (int64_t x = 0; x < n; ++x) {
        int64_t k = min_sum0 - sum;
        if ((k + x * MOD) % n) { continue; }
        s0 = (k + x * MOD) / n;
        break;
    }
    sum += n * (n + 1) / 2;
    sum %= MOD;
    int64_t s1 = -1, min_sum1 = (sum + nMOD * ((MOD - sum + nMOD - 1) / nMOD)) % MOD;
    assert(sum >= min_sum1);
    for (int64_t x = 0; x < n; ++x) {
        int64_t k = min_sum1 - sum;
        if ((k + x * MOD) % n) { continue; }
        s1 = (k + x * MOD) / n;
        break;
    }
    if (min_sum0 < min_sum1) {
        cout << min_sum0 << "\n" << (s0 + MOD) % MOD << " " << 0;
    } else {
        cout << min_sum1 << "\n" << (s1 + MOD) % MOD << " " << 1;
    }
}
