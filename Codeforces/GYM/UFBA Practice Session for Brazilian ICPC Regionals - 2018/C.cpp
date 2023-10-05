/**
 *    author:  MaGnsi0
 *    created: 06.09.2023 04:09:44
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

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
    int T;
    cin >> T;
    while (T--) {
        int64_t n;
        cin >> n; n -= 2;
        if (n == -1) {
            cout << 0 << "\n";
            continue;
        }
        int64_t ans = (n - 1) % MOD * power(2, n + 2) % MOD;
        ans = (ans + n % MOD + 5) % MOD;
        cout << ans << "\n";
    }
}
