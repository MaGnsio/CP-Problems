/**
 *    author:  MaGnsi0
 *    created: 29.12.2024 23:32:48
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        int64_t k; cin >> k;
        function<pair<int64_t, int64_t>(int64_t)> F = [&](int64_t m) {
            if (m < k) {
                return make_pair(int64_t(0), int64_t(0));
            }
            auto [x, y] = F(m / 2);
            if (m & 1) {
                return make_pair(2 * x + (y + 1) * (m + 1) / 2, 2 * y + 1);
            } else {
                return make_pair(2 * x + y * (m / 2), 2 * y);
            }
        };
        int64_t ans = F(n).first;
        cout << ans << "\n";
    }
}
