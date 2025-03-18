/**
 *    author:  MaGnsi0
 *    created: 18.03.2025 04:58:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        vector<int64_t> a(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }
        vector<int64_t> b(n + 2, 0);
        for (int i = 0; i < m; ++i) {
            int64_t x = a[i];
            b[1]++; b[x + 1]--;
        }
        for (int i = 1; i < n + 2; ++i) {
            b[i] += b[i - 1];
        }
        for (int i = 1; i < n + 2; ++i) {
            b[i] += b[i - 1];
        }
        int64_t ans = 0;
        for (int i = 0; i < m; ++i) {
            int j = max<int>(n - a[i], 1);
            ans += b[n - 1] - b[j - 1];
            ans -= max<int>(min<int>(n - 1, a[i]) - j + 1, 0);
        }
        cout << ans << "\n";
    }
}
