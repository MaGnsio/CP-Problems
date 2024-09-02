/**
 *    author:  MaGnsi0
 *    created: 02.09.2024 22:40:51
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
        if (n == 1) {
            cout << (k <= a[0] ? k - 1 : k) << "\n";
            continue;
        }
        int64_t g = 0;
        for (int i = 0; i < n; ++i) {
            g = __gcd(g, a[i]);
        }
        int64_t ans = -1;
        for (int64_t x = 0; x < n; ++x) {
            if (k + x <= x * g) {
                ans = k + x - 1;
                break;
            }
        }
        if (ans == -1) { ans = n + k - 1; }
        cout << ans << "\n";
    }
}
