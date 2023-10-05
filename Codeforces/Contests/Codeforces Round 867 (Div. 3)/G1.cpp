/**
 *    author:  MaGnsi0
 *    created: 24.04.2023 18:12:37
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<int64_t, int64_t> mp;
        for (int i = 0; i < n; ++i) {
            int64_t x;
            cin >> x;
            mp[x]++;
        }
        int64_t ans = 0;
        for (auto& [x, y] : mp) {
            for (int64_t j = 1; j * j <= x; ++j) {
                if (x % j) { continue; }
                int64_t b = x / j;
                if (mp.count(x * b) && mp.count(j)) {
                    if (b == 1) {
                        ans += y * (y - 1) * (y - 2);
                    } else {
                        ans += mp[j] * mp[x] * mp[x * b];
                    }
                }
                if (j * j == x) { continue; }
                b = j;
                if (mp.count(x * b) && mp.count(x / j)) {
                    if (b == 1) {
                        ans += y * (y - 1) * (y - 2);
                    } else {
                        ans += mp[x / j] * mp[x] * mp[x * b];
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}
