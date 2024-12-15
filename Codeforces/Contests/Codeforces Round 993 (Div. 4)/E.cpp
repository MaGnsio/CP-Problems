/**
 *    author:  MaGnsi0
 *    created: 15.12.2024 17:57:48
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e12;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;
        int64_t ans = 0;
        for (int64_t f = 1; f <= OO; f *= k) {
            int64_t L = max(l1, (l2 + f - 1) / f);
            int64_t R = min(r1, r2 / f);
            int64_t add = max(R - L + 1, int64_t(0));
            ans += add;
        }
        cout << ans << "\n";
    }
}
