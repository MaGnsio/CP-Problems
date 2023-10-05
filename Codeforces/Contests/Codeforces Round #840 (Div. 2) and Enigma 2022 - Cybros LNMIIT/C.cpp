/**
 *    author:  MaGnsi0
 *    created: 20.12.2022 22:23:17
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n;
        cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int64_t maxe = *max_element(a.begin(), a.end());
        if (n >= 4) {
            cout << n * maxe << "\n";
        } else if (n == 2) {
            cout << max(a[0] + a[1], 2 * abs(a[0] - a[1])) << "\n";
        } else {
            assert(n == 3);
            if (maxe == a[0] || maxe == a[2]) {
                cout << n * maxe << "\n";
            } else {
                int64_t ans = a[0] + a[1] + a[2];
                ans = max(ans, n * a[0]);
                ans = max(ans, n * a[2]);
                ans = max(ans, n * abs(a[0] - a[1]));
                ans = max(ans, n * abs(a[0] - a[2]));
                ans = max(ans, n * abs(a[1] - a[2]));
                cout << ans << "\n";
            }
        }
    }
}
