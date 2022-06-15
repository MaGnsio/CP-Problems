/**
 *    author:  MaGnsi0
 *    created: 30.04.2022 16:34:18
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t b, q, y;
        cin >> b >> q >> y;
        int64_t c, r, z;
        cin >> c >> r >> z;
        if (!(c >= b && (c - b) % q == 0 && r >= q && r % q == 0 && b + q * (y - 1) >= c + r * (z - 1))) {
            cout << 0 << "\n";
            continue;
        }
        if (c - r < b || c + r * z > b + q * (y - 1)) {
            cout << -1 << "\n";
            continue;
        }
        auto solve = [&](int64_t x) {
            if (x * q / __gcd(x, q) != r) {
                return int64_t(0);
            }
            int64_t R = c + r * (z - 1) + x * (q / __gcd(q, x));
            int64_t L = c - x * (q / __gcd(q, x));
            int64_t res = (abs(L - c) / x) * (abs(c + r * (z - 1) - R) / x);
            return (int64_t)(res % MOD);
        };
        int64_t ans = 0;
        for (int i = 1; i * i <= r; ++i) {
            if (r % i == 0) {
                ans += solve(i);
                ans %= MOD;
                if (i * i != r) {
                    ans += solve(r / i);
                    ans %= MOD;
                }
            }
        }
        cout << ans << "\n";
    }
}
