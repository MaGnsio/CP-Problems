/**
 *    author:  MaGnsi0
 *    created: 02.05.2022 20:49:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        if (y % x) {
            cout << "0 0\n";
        } else {
            cout << 1 << " " << y / x << "\n";
        }
    }
}
