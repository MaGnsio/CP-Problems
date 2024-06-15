/**
 *    author:  MaGnsi0
 *    created: 15.06.2024 18:43:13
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 5e10;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t h; cin >> h;
        int n; cin >> n;
        vector<int64_t> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        function<bool(int64_t)> F = [&](int64_t turns) {
            __int128 dmg = 0;
            for (int i = 0; i < n; ++i) {
                dmg += __int128((turns + b[i] - 1) / b[i]) * a[i];
            }
            return dmg >= h;
        };
        int64_t low = 1, high = N, ans = -1;
        while (low <= high) {
            int64_t mid = low + (high - low) / 2;
            if (F(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}
