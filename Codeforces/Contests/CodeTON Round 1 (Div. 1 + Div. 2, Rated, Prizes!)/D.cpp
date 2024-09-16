/**
 *    author:  MaGnsi0
 *    created: 16.09.2024 20:16:07
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        if (!(n & (n - 1))) {
            cout << "-1\n";
        } else if (n & 1) {
            cout << "2\n";
        } else {
            int64_t p = 1;
            while (n % 2 == 0) { n /= 2; p++; }
            __int128 x = (1LL << p);
            __int128 k1 = x > 1e9 ? 1e18 : x * (x + 1) / 2;
            __int128 k2 = n > 1e9 ? 1e18 : n * (n + 1) / 2;
            int64_t ans = k1 < k2 ? x : n;
            cout << ans << "\n";
        }
    }
}
