/**
 *    author:  MaGnsi0
 *    created: 04.04.2026 17:11:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int x; cin >> x;
        int y; cin >> y;
        if ((x + y) & 1) { y--; }
        else { x--; }
        if (x < 0 || y < 0 || x > y) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        set<int> evens, odds;
        for (int i = 2, j = 0; j < x; ++i, ++j) {
            evens.insert(i);
        }
        for (int i = x + 2, j = 0; j < y; ++i, ++j) {
            odds.insert(i);
        }
        for (int v : evens) {
            cout << 1 << " " << v << "\n";
            cout << v << " " << *odds.begin() << "\n";
            odds.erase(odds.begin());
        }
        for (int v : odds) {
            cout << 1 << " " << v << "\n";
        }
    }
}
