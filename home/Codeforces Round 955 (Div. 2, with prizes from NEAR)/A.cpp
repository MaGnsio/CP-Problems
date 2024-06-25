/**
 *    author:  MaGnsi0
 *    created: 25.06.2024 17:36:31
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << ((x1 != y1) && (x2 != y2) && ((x1 < y1) == (x2 < y2)) ? "YES" : "NO") << "\n";
    }
}
