/**
 *    author:  MaGnsi0
 *    created: 24.12.2024 16:35:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        function<int64_t(int64_t)> solve = [&](int64_t x) {
            if (x < 4) { return int64_t(1); }
            return 2 * solve(x / 4);
        };
        int64_t ans = solve(n);
        cout << ans << "\n";
    }
}
