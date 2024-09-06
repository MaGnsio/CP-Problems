/**
 *    author:  MaGnsi0
 *    created: 07.09.2024 00:45:18
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
        int X = (x + k - 1) / k;
        int Y = (y + k - 1) / k;
        cout << max(2 * X - 1, 2 * Y) << "\n";
    }
}
