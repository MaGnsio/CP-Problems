/**
 *    author:  MaGnsi0
 *    created: 27.01.2024 16:49:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t x; cin >> x;
        int64_t n; cin >> n;
        int64_t ans = 1;
        for (int64_t y = 1; y * y <= x; ++y) {
            if (x % y) { continue; }
            if (x / y >= n) {
                ans = max(ans, y);
            }
            if (x / (x / y) >= n) {
                ans = max(ans, x / y);
            }
        }
        cout << ans << "\n";
    }
}
