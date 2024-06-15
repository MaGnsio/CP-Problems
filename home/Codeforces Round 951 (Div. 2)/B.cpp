/**
 *    author:  MaGnsi0
 *    created: 06.06.2024 17:44:02
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t x; cin >> x;
        int64_t y; cin >> y;
        for (int b = 0; b <= 31; ++b) {
            if ((x >> b & 1) != (y >> b & 1)) {
                cout << (1 << b) << "\n";
                break;
            }
        }
    }
}
