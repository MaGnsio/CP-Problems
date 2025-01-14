/**
 *    author:  MaGnsi0
 *    created: 14.01.2025 19:14:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        sort(a.begin() + 1, a.end());
        sort(b.begin(), b.end());
        vector<int64_t> bad(m, 0);
        for (int i = 0; i < m; ++i) {
            if (b[i] <= a[0]) { continue; }
            bad[i] = a.end() - lower_bound(a.begin() + 1, a.end(), b[i]);
        }
        sort(bad.begin(), bad.end());
        for (int k = 1; k <= m; ++k) {
            int contests = m / k;
            int64_t ans = 0;
            for (int i = 0, j = 0; j < contests; ++j) {
                ans += bad[k + i - 1] + 1;
                i += k;
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
}
