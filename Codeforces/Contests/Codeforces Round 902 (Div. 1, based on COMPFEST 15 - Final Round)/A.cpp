/**
 *    author:  MaGnsi0
 *    created: 08.10.2023 16:57:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, p;
        cin >> n >> p;
        vector<int64_t> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        iota(c.begin(), c.end(), 0);
        sort(c.begin(), c.end(), [&](int64_t i, int64_t j) {
                return b[i] < b[j];
            });
        int64_t ans = p, rem = n - 1;
        for (int64_t j : c) {
            if (b[j] >= p) {
                ans += rem * p;
                break;
            }
            ans += min(rem, a[j]) * b[j];
            rem = max(int64_t(0), rem - a[j]);
        }
        cout << ans << "\n";
    }
}
