/**
 *    author:  MaGnsi0
 *    created: 15.09.2023 17:43:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t x, y, z;
        cin >> x >> y >> z;
        //(x + y - z) % k == 0
        int64_t k = x + y - z;
        if (k == 0) { k = 2e9; }
        if (k < 0) {
            cout << -1 << "\n";
        } else if (k <= x || (x + y) % k != z) {
            cout << -1 << "\n";
        } else {
            assert((x + y) % k == z);
            cout << k << "\n";
        }
    }
}
