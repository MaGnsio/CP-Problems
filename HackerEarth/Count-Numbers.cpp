/**
 *    author:  MaGnsi0
 *    created: 28.05.2022 14:01:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        int64_t l, r, ans = 0;
        cin >> l >> r;
        for (int j = 1; j < (1 << n); ++j) {
            int64_t x = 1;
            for (int k = 0; k < n; ++k) {
                if ((j >> k) & 1) {
                    x *= a[k];
                }
            }
            ans += (__builtin_popcount(j) & 1 ? 1 : -1) * (r / x - (l - 1) / x);
        }
        cout << ans << "\n";
    }
}
