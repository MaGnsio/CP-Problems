/**
 *    author:  MaGnsi0
 *    created: 10.11.2024 18:07:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        int64_t x; cin >> x;
        vector<int64_t> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            a[i] += a[i - 1];
        }
        vector<int64_t> dppre(n + 2, 0), dpsuf(n + 2, 0);
        for (int i = 1; i <= n; ++i) {
            if (a[i] < x) { continue; }
            int low = 1, high = i, j = i;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (a[i] - a[mid - 1] >= x) {
                    j = mid; low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            dppre[i] = dppre[j - 1] + 1;
        }
        for (int i = n; i >= 1; --i) {
            if (a[n] - a[i - 1] < x) { continue; }
            int low = i, high = n, j = i;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (a[mid] - a[i - 1] >= x) {
                    j = mid; high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            dpsuf[i] = dpsuf[j + 1] + 1;
        }
        int64_t ans = -1;
        for (int i = 1; i <= n; ++i) {
            int64_t need = max(m - dppre[i], int64_t(0));
            if (need == 0) {
                ans = max(ans, a[n] - a[i]);
                continue;
            }
            int64_t low = i + 1, high = n, j = -1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (dpsuf[mid] >= need) {
                    j = mid; low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            if (j != -1) {
                ans = max(ans, a[j - 1] - a[i]);
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (dpsuf[i] >= m) {
                ans = max(ans, a[i - 1]);
            }
        }
        cout << ans << "\n";
    }
}
