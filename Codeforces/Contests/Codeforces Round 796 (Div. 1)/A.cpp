/**
 *    author:  MaGnsi0
 *    created: 15.01.2025 23:39:34
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
        for (int i = 1; i < n; ++i) {
            a[i] += a[i - 1];
        }
        if (k >= n) {
            int64_t ans = a[n - 1] + n * k - n * (n + 1) / 2;
            cout << ans << "\n";
        } else {
            int64_t ans = 0;
            for (int i = k - 1; i < n; ++i) {
                ans = max(ans, a[i] - (i - k >= 0 ? a[i - k] : 0) + k * (k - 1) / 2);
            }
            cout << ans << "\n";
        }
    }
}
