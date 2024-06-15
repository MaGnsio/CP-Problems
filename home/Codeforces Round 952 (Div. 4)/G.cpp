/**
 *    author:  MaGnsi0
 *    created: 15.06.2024 19:22:24
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int64_t power(int64_t b, int64_t p) {
    int64_t res = 1; b %= MOD;
    while (p) {
        if (p & 1) { res = res * b % MOD; }
        b = b * b % MOD;
        p /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t L; cin >> L;
        int64_t R; cin >> R;
        int64_t K; cin >> K;
        int64_t X = 9 / K + 1;
        cout << (power(X, R) - power(X, L) + MOD) % MOD  << "\n";
    }
}
