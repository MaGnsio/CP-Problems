/**
 *    author:  MaGnsi0
 *    created: 22.09.2024 16:26:15
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
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        int64_t s; cin >> s;
        int64_t m; cin >> m;
        if (n & 1) {
            cout << (power(2, s) + MOD - 1) % MOD << "\n";
        } else {
            int64_t low = 0, high = s, s_ = 0;
            while (low <= high) {
                int64_t mid = (low + high) / 2;
                int64_t ns = s - mid;
                int64_t rm = (ns + n - 1) / n;
                if (s - rm >= m) {
                    s_ = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            int64_t x = (power(2, s) + MOD - 1) % MOD;
            int64_t y = (power(2, s_) + MOD - 1) % MOD;
            cout << (x - y + MOD) % MOD << "\n";
        }
    }
}
