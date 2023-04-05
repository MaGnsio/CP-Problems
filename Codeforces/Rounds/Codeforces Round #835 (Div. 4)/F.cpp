/**
 *    author:  MaGnsi0
 *    created: 29.11.2022 18:22:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, c, d;
        cin >> n >> c >> d;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        int64_t sum = accumulate(a.begin(), a.begin() + min(n, d), int64_t(0));
        if (sum >= c) {
            cout << "Infinity\n";
            continue;
        }
        if (d * a[0] < c) {
            cout << "Impossible\n";
            continue;
        }
        int64_t l = 0, r = d - 1, ans = 0;
        while (l <= r) {
            int64_t m = (l + r) / 2;
            int64_t sum = 0;
            for (int i = 0; i < min(n, m + 1); ++i) {
                sum += (d / (m + 1)) * a[i];
                sum += (d % (m + 1) > i) * a[i];
            }
            if (sum >= c) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        assert(ans < d);
        cout << ans << "\n";
    }
}
