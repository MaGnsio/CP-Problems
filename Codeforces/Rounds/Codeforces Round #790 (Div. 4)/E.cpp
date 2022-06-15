/**
 *    author:  MaGnsi0
 *    created: 11.05.2022 15:58:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end(), greater<int64_t>());
        for (int i = 1; i < n; ++i) {
            a[i] += a[i - 1];
        }
        for (int i = 0; i < q; ++i) {
            int64_t x;
            cin >> x;
            int l = 0, r = n - 1, ans = -1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (a[m] >= x) {
                    ans = m + 1;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            cout << ans << "\n";
        }
    }
}
