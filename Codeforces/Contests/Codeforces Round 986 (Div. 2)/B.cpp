/**
 *    author:  MaGnsi0
 *    created: 10.11.2024 17:43:32
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        int64_t b; cin >> b;
        int64_t c; cin >> c;
        if (b == 0) {
            if (c < n - 2) {
                cout << -1 << "\n";
            } else {
                cout << n - (c <= n - 1) << "\n";
            }
            continue;
        }
        int64_t low = 0, high = n - 1, ans = 0;
        while (low <= high) {
            int64_t mid = low + (high - low) / 2;
            if (n - c - 1 < 0 || mid > (n - c - 1) / b) {
                ans = n - mid; high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}
