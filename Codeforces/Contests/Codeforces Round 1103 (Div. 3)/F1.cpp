/**
 *    author:  MaGnsi0
 *    created: 21.06.2026 23:16:00
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int _; cin >> _;
        map<int, int64_t> mp;
        for (int i = 0; i < n; ++i) {
            int y; cin >> y;
            for (int j = 2; j * j <= y; ++j) {
                while (y % j == 0) { y /= j; mp[j]++; }
            }
            if (y > 1) { mp[y]++; }
        }
        int64_t ans = 1;
        for (auto [_, y] : mp) {
            ans *= (y + 1);
            ans %= MOD;
        }
        cout << ans << "\n";
    }
}
