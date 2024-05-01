/**
 *    author:  MaGnsi0
 *    created: 30.04.2024 18:26:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        int64_t m; cin >> m;
        int64_t ans = 0;
        function<int(int64_t, int64_t, int64_t)> F = [&](int64_t a, int64_t b, int64_t x) {
            if (__gcd(a, b) != x) { return 0; }
            if (b > m) { return 0; }
            return int((a + b) % (b * x) == 0);
        };
        for (int64_t a = 1; a <= n; ++a) {
            for (int64_t x = 1; x * x <= a; ++x) {
                if (a % x == 0) {
                    ans += F(a, a / x, x);
                    ans += (a != x * x) * F(a, x, a / x);
                }
            }
        }
        cout << ans << "\n";
    }
}
