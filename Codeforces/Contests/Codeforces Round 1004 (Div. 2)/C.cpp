/**
 *    author:  MaGnsi0
 *    created: 11.02.2025 17:01:09
**/
#include <bits/stdc++.h>

using namespace std;

bool have7(int64_t x) {
    while (x) {
        if (x % 10 == 7) { return true; }
        x /= 10;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        int64_t ans = 7, a[10] = {9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999, 9999999999};
        for (int64_t x : a) {
            for (int64_t i = 0; i < 7; ++i) {
                if (have7(n + i * x)) {
                    ans = min(ans, i);
                }
            }
        }
        cout << ans << "\n";
    }
}
