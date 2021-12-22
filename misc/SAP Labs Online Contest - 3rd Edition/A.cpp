/**
 *    author:  MaGnsi0
 *    created: 11.12.2021 19:17:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int x, ys, ye;
    cin >> x >> ys >> ye;
    if (ys > ye) {
        swap(ys, ye);
    }
    int minx = min(x1, x2), maxx = max(x1, x2);
    int miny = min(y1, y2), maxy = max(y1, y2);
    if (minx <= x && x <= maxx && ys <= miny && maxy <= ye) {
        cout << abs(x1 - x2) + abs(y1 - y2) + 2 * min((ys ? abs(miny - ys) + 1 : INT_MAX), abs(maxy - ye) + 1) << "\n";
    } else {
        cout << abs(x1 - x2) + abs(y1 - y2) << "\n";
    }
}
