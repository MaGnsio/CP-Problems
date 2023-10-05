/**
 *    author:  MaGnsi0
 *    created: 06.09.2023 04:34:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n;
        cin >> n;
        int64_t ans = 0;
        for (int i = 0; (1LL << i) <= n; ++i) {
            int64_t x = (n >> 1) / (1LL << i) - (n >> 1) / (1LL << (i + 1));
            int64_t y = 1LL * i * (1LL << (i + 1)) + 1;
            ans += x * y;
        }
        cout << ans << "\n";
    }
}
