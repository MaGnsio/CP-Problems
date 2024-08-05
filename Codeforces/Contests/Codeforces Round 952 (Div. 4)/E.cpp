/**
 *    author:  MaGnsi0
 *    created: 15.06.2024 18:33:33
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t x, y, z, K;
        cin >> x >> y >> z >> K;
        int64_t ans = 0;
        for (int64_t i = 1; i <= x; ++i) {
            for (int64_t j = 1; j <= y; ++j) {
                if (K % (i * j)) { continue; }
                int64_t k = K / (i * j);
                if (k > z) { continue; }
                ans = max(ans, (x - i + 1) * (y - j + 1) * (z - k + 1));
            }
        }
        cout << ans << "\n";
    }
}
