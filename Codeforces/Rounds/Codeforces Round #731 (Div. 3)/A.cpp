/**
 *    author:  MaGnsi0
 *    created: 10/07/2021 16:35:58
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        int dist = abs(x1 - x2) + abs(y1 - y2);
        if (x1 == x2 && x2 == x3 && ((y1 < y3 && y3 < y2) ||(y1 > y3 && y3 > y2))) {
            dist += 2;
        }
        if (y1 == y2 && y2 == y3 && ((x1 < x3 && x3 < x2) ||(x1 > x3 && x3 > x2))) {
            dist += 2;
        }
        cout << dist << "\n";
    }
}
