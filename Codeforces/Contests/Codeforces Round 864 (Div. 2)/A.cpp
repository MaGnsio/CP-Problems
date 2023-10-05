/**
 *    author:  MaGnsi0
 *    created: 08.04.2023 16:06:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = 4;
        if (x1 == n || x1 == 1) { ans = 3; }
        if (y1 == 1 || y1 == m) { ans = 3; }
        if (x2 == n || x2 == 1) { ans = 3; }
        if (y2 == 1 || y2 == m) { ans = 3; }
        if ((x1 == 1 || x1 == n) && (y1 == 1 || y1 == m)) { ans = 2; }
        if ((x2 == 1 || x2 == n) && (y2 == 1 || y2 == m)) { ans = 2; }
        cout << ans << "\n";
    }
}
