/**
 *    author:  MaGnsi0
 *    created: 07.09.2024 01:17:49
**/
#include <bits/stdc++.h>

using namespace std;

int64_t sum(int64_t x) {
    return x * (x + 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        int64_t k; cin >> k;
        int64_t low = 0, high = n - 1, x = 0;
        while (low <= high) {
            int64_t mid = (low + high) / 2;
            int64_t L = max(sum(k + mid) - sum(k - 1), 0LL);
            int64_t R = max(sum(k + n - 1) - sum(k + mid), 0LL);
            if (L <= R) {
                x = mid; low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        int64_t ans = abs(max(sum(k + x) - sum(k - 1), 0LL) - max(sum(k + n - 1) - sum(k + x), 0LL)); x++;
        ans = min(ans, abs(max(sum(k + x) - sum(k - 1), 0LL) - max(sum(k + n - 1) - sum(k + x), 0LL)));
        cout << ans << "\n";
    }
}
