/**
 *    author:  MaGnsi0
 *    created: 29.09.2024 18:36:39
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        int64_t k; cin >> k;
        int ans = 0;
        while (n) {
            if (k == 1 || k > n) {
                ans += n;
                n = 0;
                continue;
            }
            int64_t minus = 0;
            for (int64_t p = k; p <= n; p *= k) {
                minus = p;
            }
            n -= minus; ans++;
        }
        cout << ans << "\n";
    }
}
