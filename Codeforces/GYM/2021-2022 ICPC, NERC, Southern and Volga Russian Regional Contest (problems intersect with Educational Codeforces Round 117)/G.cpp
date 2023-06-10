/**
 *    author:  MaGnsi0
 *    created: 07.04.2023 23:45:39
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t k, x;
        cin >> k >> x;
        int64_t low = 1, high = 2 * k - 1, ans = 2 * k - 1;
        while (low <= high) {
            int64_t mid = low + (high - low) / 2;
            int64_t sum = (mid <= k ? mid * (mid + 1) / 2 : k * (k + 1) / 2 + k * (k - 1) / 2 - (k - mid + k) * (k - mid + k - 1) / 2);
            if (sum >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}
