/**
 *    author:  MaGnsi0
 *    created: 11.02.2025 16:39:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int x; cin >> x;
        int y; cin >> y;
        if (x + 1 == y) {
            cout << "YES\n";
        } else if (x > y && (x - y + 1) % 9 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
