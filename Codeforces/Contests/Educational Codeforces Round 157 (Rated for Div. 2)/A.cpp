/**
 *    author:  MaGnsi0
 *    created: 24.11.2023 14:34:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int x; cin >> x;
        int y; cin >> y;
        int k; cin >> k;
        if (y <= x) {
            cout << x << "\n";
        } else {
            cout << y + max(0, y - x - k) << "\n";
        }
    }
}
