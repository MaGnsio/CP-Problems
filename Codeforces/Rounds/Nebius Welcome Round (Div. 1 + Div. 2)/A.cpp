/**
 *    author:  MaGnsi0
 *    created: 12.03.2023 16:36:54
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
        x = abs(x), y = abs(y);
        int ans = x + y + (abs(x - y) > 1 ? abs(x - y) - 1 : 0);
        cout << ans << "\n";
    }
}
