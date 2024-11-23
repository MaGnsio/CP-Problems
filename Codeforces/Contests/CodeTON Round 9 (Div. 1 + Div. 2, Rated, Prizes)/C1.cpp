/**
 *    author:  MaGnsi0
 *    created: 23.11.2024 16:46:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t x; cin >> x;
        int64_t m; cin >> m;
        int64_t ans = 0;
        for (int64_t y = 1; y <= min(2 * x, m); ++y) {
            if (y == x) { continue; }
            int64_t z = x ^ y;
            ans += (x % z == 0) || (y % z == 0);
        }
        cout << ans << "\n";
    }
}
