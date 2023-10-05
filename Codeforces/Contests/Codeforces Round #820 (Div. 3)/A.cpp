/**
 *    author:  MaGnsi0
 *    created: 12.09.2022 16:33:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        int x = abs(a - 1), y = abs(b - c) + abs(c - 1);
        if (x == y) {
            cout << 3 << "\n";
        } else if (x < y) {
            cout << 1 << "\n";
        } else {
            cout << 2 << "\n";
        }
    }
}
