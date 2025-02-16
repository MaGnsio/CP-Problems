/**
 *    author:  MaGnsi0
 *    created: 16.02.2025 16:52:07
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            int64_t x; cin >> x;
            if (x > 0) {
                a[i] = x;
            } else {
                b[i] = -x;
            }
        }
        for (int i = 1; i < n; ++i) {
            a[i] += a[i - 1];
        }
        for (int i = n - 2; i >= 0; --i) {
            b[i] += b[i + 1];
        }
        int64_t ans = max(a[n - 1], b[0]);
        for (int i = 0; i + 1 < n; ++i) {
            ans = max(ans, a[i] + b[i + 1]);
        }
        cout << ans << "\n";
    }
}
