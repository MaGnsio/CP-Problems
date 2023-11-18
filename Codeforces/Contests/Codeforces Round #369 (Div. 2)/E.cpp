/**
 *    author:  MaGnsi0
 *    created: 15.10.2023 14:44:22
**/
#include <bits/stdc++.h>

using namespace std;

int64_t MOD = 1e6 + 3;

int64_t power(__int128 b, __int128 p) {
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
    int64_t N, K;
    cin >> N >> K;
    if (N <= 63 && (1LL << N) < K) {
        cout << 1 << " " << 1;
        return 0;
    }
    __int128 p2_up = 0, p2_down = __int128(N) * (K - 1);
    for (int64_t p2 = 1; (1LL << p2) <= K; ++p2) {
        p2_up += (K - 1) / (1LL << p2);
    }
    __int128 g = min(p2_up, p2_down);
    int64_t down = power(2, p2_down - g);
    int64_t up = 0;
    if (K < MOD) {
        up = 1;
        for (int64_t x = 1; x < K; ++x) {
            up *= (power(2, N) - x + MOD) % MOD;
            up %= MOD;
        }
        up *= power(power(2, g), MOD - 2);
        up %= MOD;
    }
    up = (down - up + MOD) % MOD;
    cout << up << " " << down;
}
