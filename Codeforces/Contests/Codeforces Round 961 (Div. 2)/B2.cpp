/**
 *    author:  MaGnsi0
 *    created: 17.09.2024 02:32:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int64_t m; cin >> m;
        vector<pair<int64_t, int64_t>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> a[i].second;
        }
        sort(a.begin(), a.end());
        int64_t ans = 0;
        for (auto [x, y] : a) {
            ans = max(ans, min(m / x, y) * x);
        }
        for (int i = 1; i < n; ++i) {
            if (a[i].first - a[i - 1].first != 1) { continue; }
            auto [x1, y1] = a[i - 1];
            auto [x2, y2] = a[i];
            int64_t take1 = min(m / x1, y1);
            int64_t rem = m - take1 * x1;
            int64_t take2 = min(rem / x2, y2);
            int64_t rem_ = rem - take2 * x2;
            int64_t extra = min({y2 - take2, take1, rem_});
            take1 -= extra, take2 += extra;
            ans = max(ans, take1 * x1 + take2 * x2);
        }
        cout << ans << "\n";
    }
}
