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
        for (int64_t b = 1; b <= m; ++b) {
            for (int64_t a = b; a <= n; a += b) {
                ans += (a + b) % (b * __gcd(a, b)) == 0;
            }
        }
        cout << ans << "\n";
    }
}
