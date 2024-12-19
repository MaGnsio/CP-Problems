/**
 *    author:  MaGnsi0
 *    created: 22.09.2024 16:09:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t m; cin >> m;
        int64_t n; cin >> n;
        if (m == 1) {
            cout << n * (n - 1) / 2 << "\n";
            continue;
        }
        int64_t ans = 0, v = 1, sz = 1, steps = 0;
        while (v <= n) {
            int64_t take = min(n - v + 1, sz);
            ans += steps * take;
            v = v + sz; sz *= m; steps++;
        }
        cout << ans << "\n";
    }
}
