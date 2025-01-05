/**
 *    author:  MaGnsi0
 *    created: 05.01.2025 01:48:26
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        vector<int> l(m), r(m);
        for (int i = 0; i < m; ++i) {
            cin >> l[i] >> r[i]; l[i]--, r[i]--;
        }
        int k; cin >> k;
        vector<int> a(k);
        for (int i = 0; i < k; ++i) {
            cin >> a[i]; a[i]--;
        }
        function<bool(int)> F = [&](int x) {
            vector<int> b(n);
            for (int i = 0; i <= x; ++i) {
                b[a[i]] = 1;
            }
            for (int i = 1; i < n; ++i) {
                b[i] += b[i - 1];
            }
            for (int i = 0; i < m; ++i) {
                int ones = b[r[i]] - (l[i] ? b[l[i] - 1] : 0);
                if (2 * ones > r[i] - l[i] + 1) { return true; }
            }
            return false;
        };
        int low = 0, high = k - 1, ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (F(mid)) {
                ans = mid + 1; high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}
