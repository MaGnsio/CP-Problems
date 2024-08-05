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
        int64_t low = 0, high = 1e13, x = 0;
        while (low <= high) {
            int64_t mid = low + (high - low) / 2;
            int64_t need = 0;
            for (int i = 0; i < n; ++i) {
                need += max(mid - a[i], 0LL);
            }
            if (need <= k) {
                x = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        int64_t ans = x * n - n + 1;
        for (int i = 0; i < n; ++i) {
            int64_t need = max(x - a[i], 0LL);
            k -= need, a[i] += need;
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] > x) {
                ans++;
            } else if (k) {
                ans++, k--;
            }
        }
        cout << ans << "\n";
    }
}
