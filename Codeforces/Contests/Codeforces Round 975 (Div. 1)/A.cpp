/**
 *    author:  MaGnsi0
 *    created: 27.09.2024 18:13:31
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
        int64_t sum = accumulate(a.begin(), a.end(), int64_t(0));
        int ans = 0;
        for (int m = 1; m <= n; ++m) {
            int64_t need = (m - (sum % m)) % m;
            if (k < need) { continue; }
            if ((sum + need + (k - need) - (k - need) % m) / m < a[n - 1]) { continue; }
            ans = m;
        }
        cout << ans << "\n";
    }
}
