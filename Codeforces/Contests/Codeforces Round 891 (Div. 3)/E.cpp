/**
 *    author:  MaGnsi0
 *    created: 15.01.2025 23:31:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int64_t> b = a, c = a;
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        for (int i = 1; i < n; ++i) {
            b[i] += b[i - 1];
        }
        for (int i = 0; i < n; ++i) {
            int j = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
            int64_t res = b[n - 1] - (j ? 2 * b[j - 1] : 0) - (n - 2 * j) * a[i] + n;
            cout << res << (i == n - 1 ? "\n" : " ");
        }
    }
}
