/**
 *    author:  MaGnsi0
 *    created: 17.09.2024 01:45:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int64_t m; cin >> m;
        map<int64_t, int64_t> a;
        for (int i = 0; i < n; ++i) {
            int64_t x; cin >> x; a[x]++;
        }
        int64_t ans = 0, prv = -1;
        for (auto [x, y] : a) {
            ans = max(ans, min(m / x, y) * x);
        }
        for (auto [x, y] : a) {
            if (prv == -1 || x - prv != 1) {
                prv = x;
                continue;
            }
            int64_t limit = min(m / prv, a[prv]);
            for (int64_t take1 = 0; take1 <= limit; ++take1) {
                int64_t rem = m - take1 * prv;
                int64_t take2 = min(rem / x, y);
                ans = max(ans, take1 * prv + take2 * x);
            }
            prv = x;
        }
        cout << ans << "\n";
    }
}
