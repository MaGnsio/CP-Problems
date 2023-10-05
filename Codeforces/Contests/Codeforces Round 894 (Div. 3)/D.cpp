/**
 *    author:  MaGnsi0
 *    created: 24.08.2023 17:51:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n;
        cin >> n;
        int64_t low = 1, high = 1e10, ans = 1;
        while (low <= high) {
            __int128 mid = low + (high - low) / 2;
            __int128 x = mid * (mid - 1) / 2;
            if (x <= n) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        ans += n - ans * (ans - 1) / 2;
        cout << ans << "\n";
    }
}
