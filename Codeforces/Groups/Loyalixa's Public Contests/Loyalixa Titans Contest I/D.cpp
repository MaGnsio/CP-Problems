/**
 *    author:  MaGnsi0
 *    created: 02.11.2024 22:30:41
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 1e6 + 6, MOD = 1e9 + 7;

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
    vector<int64_t> P8(N), P4(N), P3(N);
    P8[0] = 8, P4[0] = 4, P3[0] = 3;
    for (int64_t p = 1; p < N; ++p) {
        P8[p] = power(P8[p - 1], p);
        P4[p] = power(P4[p - 1], p);
        P3[p] = power(P3[p - 1], p);
    }
    for (int64_t p = 1; p < N; ++p) {
        P8[p] *= power(8, MOD - 2); P8[p] %= MOD;
        P4[p] *= power(4, MOD - 2); P4[p] %= MOD;
        P3[p] *= power(3, MOD - 2); P3[p] %= MOD;
    }
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int64_t any = 9LL * P8[n] % MOD;
        int64_t odds = 5LL * P4[n] % MOD;
        int64_t evens = 4LL * P3[n] % MOD;
        int64_t ans = (any - (odds + evens) % MOD + MOD) % MOD;
        cout << ans << "\n";
    }
}
