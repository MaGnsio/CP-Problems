/**
 *    author:  MaGnsi0
 *    created: 26.09.2024 19:34:12
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int64_t x; cin >> x;
        int64_t y; cin >> y;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int64_t m = *max_element(a.begin(), a.end());
        vector<int64_t> b(m + 2), c(m + 2);
        for (int i = 0; i < n; ++i) {
            for (int64_t j = 1; j <= a[i]; ++j) {
                int64_t take1 = (a[i] / j);
                int64_t take2 = (a[i] / j) + 1;
                int64_t count1 = j - (a[i] % j);
                int64_t count2 = a[i] % j;
                int64_t val = a[i] * (a[i] - 1) / 2 - count1 * take1 * (take1 - 1) / 2 - count2 * take2 * (take2 - 1) / 2;
                b[j] += x * val;
            }
            int l = a[i] + 1, r = m;
            if (l <= r) {
                c[l] += x * a[i] * (a[i] - 1) / 2;
                c[r + 1] -= x * a[i] * (a[i] - 1) / 2;
            }
        }
        for (int i = 1; i <= m; ++i) {
            c[i] += c[i - 1];
        }
        for (int64_t i = 1; i <= m; ++i) {
            b[i] = b[i] + c[i] - (i - 1) * y;
        }
        int64_t ans = 0;
        for (int i = 0; i <= m; ++i) {
            ans = max(ans, b[i]);
        }
        cout << ans << "\n";
    }
}
