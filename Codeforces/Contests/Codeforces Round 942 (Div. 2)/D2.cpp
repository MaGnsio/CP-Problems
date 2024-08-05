/**
 *    author:  MaGnsi0
 *    created: 07.05.2024 18:35:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        int sn = sqrt(n);
        int sm = sqrt(m);
        int64_t ans = 0;
        for (int x = 1; x <= sn; ++x) {
            for (int y = 1; y <= sm; ++y) {
                if (__gcd(x, y) != 1) { continue; }
                int limit = min(n / x, m / y);
                ans += limit / (x + y);
            }
        }
        cout << ans << "\n";
    }
}
