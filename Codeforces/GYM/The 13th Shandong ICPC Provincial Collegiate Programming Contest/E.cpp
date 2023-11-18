/**
 *    author:  MaGnsi0
 *    created: 13.10.2023 21:42:32
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, k, m, a, b;
        cin >> n >> k >> m >> a >> b;
        if (k == 1) {
            cout << (n % m == 0 ? 0 : -1) << "\n";
            continue;
        }
        int64_t ans = INT64_MAX, add = 0;
        while (n) {
            int64_t high = 1, rem = n % m;
            for (int64_t j = 0; j <= 30; ++j) {
                int64_t need = (m - rem) % m;
                if (need < high) {
                    ans = min(ans, j * a + add);
                    break;
                }
                if (high > m) { break; }
                high = k * high;
                rem = (rem * k) % m;
            }
            add += b;
            n /= k;
        }
        ans = min(ans, add);
        cout << (ans == INT64_MAX ? -1 : ans) << "\n";
    }
}
