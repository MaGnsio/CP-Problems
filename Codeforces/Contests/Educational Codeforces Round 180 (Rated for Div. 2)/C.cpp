/**
 *    author:  MaGnsi0
 *    created: 23.06.2025 17:51:40
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int64_t ans = 0;
        for (int b1 = 0; b1 < n; ++b1) {
            for (int b2 = b1 + 1; b2 < n; ++b2) {
                int j = lower_bound(a.begin(), a.end(), a[b1] + a[b2]) - a.begin();
                int k = upper_bound(a.begin(), a.end(), a[n - 1] - (a[b1] + a[b2])) - a.begin();
                k = max(k, b2 + 1);
                ans += max(j - k, 0);
            }
        }
        cout << ans << "\n";
    }
}
