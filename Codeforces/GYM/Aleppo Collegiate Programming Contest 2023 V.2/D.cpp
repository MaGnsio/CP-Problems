/**
 *    author:  MaGnsi0
 *    created: 29.08.2023 14:08:57
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
        if (y == 100) {
            cout << -1 << "\n";
            continue;
        }
        int a = x;
        int b = (y * a + 100 - y - 1) / (100 - y);
        cout << a + b << "\n";
    }
}
