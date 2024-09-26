/**
 *    author:  MaGnsi0
 *    created: 26.09.2024 19:05:42
**/
#include <bits/stdc++.h>

using namespace std;

bool F(int x, int y) {
    if ((x % 2 == 0) && (min(x / 2, 2 * y) != min(x, y) || max(x / 2, 2 * y) != max(x, y))) {
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int x; cin >> x;
        int y; cin >> y;
        cout << (F(x, y) || F(y, x) ? "YES" : "NO") << "\n";
    }
}
