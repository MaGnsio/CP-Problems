/**
 *    author:  MaGnsi0
 *    created: 30.10.2023 20:12:11
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t L; cin >> L;
        int64_t R; cin >> R;
        int64_t ans = 0;
        for (__int128 P2 = 4, lg = 2; P2 <= R; P2 *= 2, ++lg) {
            __int128 low = max(P2, __int128(L));
            __int128 high = min(2 * P2 - 1, __int128(R));
            if (low > high) { continue; }
            for (__int128 Plg = lg, g = 1; Plg <= high; Plg *= lg, ++g) {
                __int128 _low = max(Plg, low);
                __int128 _high = min(lg * Plg - 1, high);
                if (_low > _high) { continue; }
                ans += g * (_high - _low + 1) % MOD;
                ans %= MOD;
            }
        }
        cout << ans << "\n";
    }
}
