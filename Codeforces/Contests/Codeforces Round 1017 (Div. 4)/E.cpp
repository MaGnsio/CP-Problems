/**
 *    author:  MaGnsi0
 *    created: 13.04.2025 20:37:59
**/
#include <bits/stdc++.h>

using namespace std;

const int B = 31;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> a(n), f(B);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            for (int b = 0; b < B; ++b) {
                f[b] += a[i] >> b & 1;
            }
        }
        int64_t ans = 0;
        for (int i = 0; i < n; ++i) {
            int64_t val = 0;
            for (int b = 0; b < B; ++b) {
                int x = a[i] >> b & 1;
                val += (1LL << b) * (x ? n - f[b] : f[b]);
            }
            ans = max(ans, val);
        }
        cout << ans << "\n";
    }
}
