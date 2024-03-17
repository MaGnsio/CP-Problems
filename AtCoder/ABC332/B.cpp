/**
 *    author:  MaGnsi0
 *    created: 10.12.2023 14:03:17
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k, g, m;
    cin >> k >> g >> m;
    int x = 0, y = 0;
    while (k--) {
        if (x == g) {
            x = 0;
        } else if (y == 0) {
            y = m;
        } else {
            int z = min(g - x, y);
            x += z, y -= z;
        }
    }
    cout << x << " " << y;
}
