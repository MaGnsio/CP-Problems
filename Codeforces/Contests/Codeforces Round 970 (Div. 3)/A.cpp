/**
 *    author:  MaGnsi0
 *    created: 01.09.2024 17:36:06
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int x; cin >> x;
        int y; cin >> y;
        if ((x % 2 == 0) && (y % 2 == 0)) {
            cout << "YES\n";
        } else if ((x % 2 == 0) && x) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
