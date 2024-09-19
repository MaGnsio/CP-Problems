/**
 *    author:  MaGnsi0
 *    created: 19.09.2024 18:09:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t x; cin >> x;
        int64_t y; cin >> y;
        int ans = 0;
        for (int64_t p = 1; (1LL << p) <= y; ++p) {
            if ((1LL << p) >= x) {
                ans = p;
            }
        }
        cout << ans << "\n";
    }
}
