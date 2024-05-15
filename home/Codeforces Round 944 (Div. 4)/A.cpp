/**
 *    author:  MaGnsi0
 *    created: 15.05.2024 19:29:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int x; cin >> x;
        int y; cin >> y;
        if (x > y) { swap(x, y); }
        cout << x << " " << y << "\n";
    }
}
