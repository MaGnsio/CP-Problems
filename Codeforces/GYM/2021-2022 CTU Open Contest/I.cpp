/**
 *    author:  MaGnsi0
 *    created: 31.01.2024 23:23:19
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t L1; cin >> L1;
        int64_t L2; cin >> L2;
        int64_t T1; cin >> T1;
        int64_t T2; cin >> T2;
        int64_t ans = L1 * T1;
        ans = min(ans, abs(L1 - L2) * T2 + L1 * T2);
        ans = min(ans, abs(L1 - L2) * T1 + L2 * T2);
        cout << ans << "\n";
    }
}
