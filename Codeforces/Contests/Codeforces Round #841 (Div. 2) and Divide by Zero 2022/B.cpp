/**
 *    author:  MaGnsi0
 *    created: 27.12.2022 16:42:29
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

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
    int64_t half = power(2, MOD - 2);
    int64_t six = power(6, MOD - 2);
    int T;
    cin >> T;
    while (T--) {
        int64_t n;
        cin >> n;
        int64_t val1 = n;
        val1 *= n + 1;
        val1 %= MOD;
        val1 *= 2 * n + 1;
        val1 %= MOD;
        val1 *= six;
        val1 %= MOD;
        int64_t val2 = n - 1;
        val2 *= n;
        val2 %= MOD;
        val2 *= 2 * n - 1;
        val2 %= MOD;
        val2 *= six;
        val2 %= MOD;
        int64_t val3 = n;
        val3 *= n - 1;
        val3 %= MOD;
        val3 *= half;
        val3 %= MOD;
        int64_t ans = (val1 + val2 + val3) % MOD;
        cout << 2022 * ans % MOD << "\n";
    }
}
