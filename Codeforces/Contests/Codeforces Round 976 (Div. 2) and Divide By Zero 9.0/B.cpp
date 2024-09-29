/**
 *    author:  MaGnsi0
 *    created: 29.09.2024 18:42:20
**/
#include <bits/stdc++.h>

using namespace std;

int64_t sqrt_floor(int64_t x) {
    int64_t low = 1, high = sqrt(x) + 100, ans = 1;
    while (low <= high) {
        int64_t mid = low + (high - low) / 2;
        if (mid * mid <= x) {
            ans = mid; low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t k; cin >> k;
        int64_t low = 1, high = 2e18, ans = k;
        while (low <= high) {
            int64_t mid = low + (high - low) / 2;
            int64_t m = mid - sqrt_floor(mid);
            if (m >= k) {
                ans = mid; high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}
