/**
 *    author:  MaGnsi0
 *    created: 10.07.2023 01:14:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("zeros.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int64_t x, y, MOD, k;
        cin >> x >> y >> MOD >> k;
        int64_t n = x + y, n1 = n / 2, n2 = n - n1;
        vector<vector<map<int64_t, int>>> a(n + 1, vector<map<int64_t, int>>(n + 1)); 
        for (int64_t mask = 0; mask < (1 << n1); ++mask) {
            if (((mask >> (n1 - 1)) & 1) == 0) { continue; }
            int64_t val = mask;
            for (int i = 0; i < n2; ++i) {
                val = 2 * val % MOD;
            }
            int O = __builtin_popcount(mask);
            int Z = n1 - O;
            a[O][Z][val]++;
        }
        if (n == 1) {
            cout << (1 % MOD >= k) << "\n";
            continue;
        }
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                int64_t P = 0;
                a[i][j][-1] = 0;
                for (auto& [_, cnt] : a[i][j]) {
                    cnt += P;
                    P = cnt;
                }
            }
        }
        function<int64_t(int, int, int, int)> Q = [&](int O, int Z, int low, int high) {
            auto it1 = prev(a[O][Z].lower_bound(low));
            auto it2 = prev(a[O][Z].upper_bound(high));
            return (it2 -> second) - (it1 -> second);
        };
        int64_t ans = 0;
        for (int64_t mask = 0; mask < (1 << n2); ++mask) {
            int64_t val = mask % MOD;
            int O = __builtin_popcount(mask);
            int Z = n2 - O;
            if (O > x || Z > y) { continue; }
            O = x - O, Z = y - Z;
            if (val <= k) {
                ans += Q(O, Z, k - val, MOD - val - 1);
            } else {
                ans += Q(O, Z, 0, MOD - val - 1);
                ans += Q(O, Z, MOD - val + k, MOD - 1); 
            }
        }
        cout << ans << "\n";
    }
}
