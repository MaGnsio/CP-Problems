/**
 *    author:  MaGnsi0
 *    created: 15.05.2024 20:21:34
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t R; cin >> R;
        int64_t ans = 0;
        for (int64_t x = 0; x <= R; ++x) {
            int64_t lowy = INT64_MAX, highy = -1;
            {
                int64_t low = 0, high = R;
                while (low <= high) {
                    int64_t mid = (low + high) / 2;
                    if (x * x + mid * mid >= R * R) {
                        lowy = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
            {
                int64_t low = 0, high = R;
                while (low <= high) {
                    int64_t mid = (low + high) / 2;
                    if (x * x + mid * mid < (R + 1) * (R + 1)) {
                        highy = mid;
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
            }
            if (lowy > highy) { continue; }
            ans += (x == 0 ? 2 : 4) * (highy - lowy + 1);
            if (lowy == 0) { ans -= (x == 0 ? 1 : 2); }
        }
        cout << ans << "\n";
    }
}
