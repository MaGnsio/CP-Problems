/**
 *    author:  MaGnsi0
 *    created: 18.10.2023 22:00:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t c; cin >> c;
        int64_t m; cin >> m;
        int64_t x; cin >> x;
        int64_t ans = 0;
        {
            int64_t y = min({c, m, x});
            ans += y, c -= y, m -= y, x -=y;
        }
        if (c && m) {
            assert(x == 0);
            int64_t low = 0, high = min(c, m), y = 0;
            while (low <= high) {
                int64_t mid = (low + high) / 2;
                if ((c - mid) + (m - mid) >= mid) {
                    y = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            ans += y;
        }
        cout << ans << "\n";
    }
}
