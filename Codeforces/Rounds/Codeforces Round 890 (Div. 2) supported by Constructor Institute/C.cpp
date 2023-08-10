/**
 *    author:  MaGnsi0
 *    created: 05.08.2023 22:42:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        function<bool(int64_t)> F = [&](int64_t x) {
            for (int i = 0; i < n; ++i) {
                if (a[i] >= x) { return true; }
                int64_t m = 0, now = x;
                for (int j = i; j < n; ++j) {
                    if (a[j] >= now) { break; }
                    if (j == n - 1) { m = 2e8; }
                    m += now - a[j]; now--;
                }
                if (m <= k) { return true; }
            }
            return false;
        };
        int64_t low = 0, high = 2e8, ans = 0;
        while (low <= high) {
            int64_t mid = (low + high) / 2;
            if (F(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << ans << "\n";
    }
}
