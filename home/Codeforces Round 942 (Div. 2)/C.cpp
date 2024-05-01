/**
 *    author:  MaGnsi0
 *    created: 30.04.2024 18:00:19
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        int64_t k; cin >> k;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int64_t low = 0, high = 1e17, ans = 0;
        while (low <= high) {
            int64_t mid = low + (high - low) / 2;
            int64_t need = (mid + n + 1) / n, extra = (mid + n + 1) % n, left = k;
            vector<int64_t> b = a;
            for (int i = 0; i < n; ++i) {
                int64_t diff = max(need - b[i], 0LL);
                left -= diff, b[i] += diff;
            }
            int64_t count = 0;
            for (int i = 0; i < n; ++i) {
                count += b[i] > need;
            }
            if (left >= max(extra - count, 0LL)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << ans + 2 << "\n";
    }
}
