/**
 *    author:  MaGnsi0
 *    created: 13.10.2024 22:45:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int x; cin >> x;
        int64_t sum = 0, maxa = 0;
        for (int i = 0; i < n; ++i) {
            int64_t x; cin >> x;
            sum += x; maxa = max(maxa, x);
        }
        int64_t ans = max(maxa, (sum + x - 1) / x);
        cout << ans << "\n";
    }
}
