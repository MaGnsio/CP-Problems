/**
 *    author:  MaGnsi0
 *    created: 19.09.2024 18:15:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        int64_t m; cin >> m;
        int64_t l = max(int64_t(0), n - m);
        int64_t r = n + m;
        function<bool(int64_t)> F = [&](int64_t b) {
            if (r - l + 1 > (1LL << b)) { return true; }
            if (l >> b & 1) { return true; }
            if (r >> b & 1) { return true; }
            return false;
        };
        int64_t ans = 0;
        for (int b = 0; (1LL << b) <= r; ++b) {
            ans += F(b) * (1LL << b);
        }
        cout << ans << "\n";
    }
}
