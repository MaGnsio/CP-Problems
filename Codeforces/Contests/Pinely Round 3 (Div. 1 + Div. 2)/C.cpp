/**
 *    author:  MaGnsi0
 *    created: 23.12.2023 16:51:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }
        sort(a.rbegin(), a.rend());
        sort(c.rbegin(), c.rend());
        set<int> sb(b.begin(), b.end());
        vector<int64_t> d(n);
        int64_t ans = 0;
        for (int i = 0; i < n; ++i) {
            int x = *sb.lower_bound(a[i]);
            d[i] = x - a[i];
            sb.erase(x);
        }
        sort(d.begin(), d.end());
        for (int i = 0; i < n; ++i) {
            ans += c[i] * d[i];
        }
        cout << ans << "\n";
    }
}
