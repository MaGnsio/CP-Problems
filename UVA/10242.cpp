/**
 *    author:  MaGnsi0
 *    created: 15.02.2022 20:04:18
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    double x0, y0, x1, y1, x2, y2, x3, y3;
    while (cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
        cout << fixed << setprecision(3);
        if (x0 == x2 && y0 == y2) {
            cout << x1 + (x3 - x0) << " " << y1 + (y3 - y0) << "\n";
        } else if (x0 == x3 && y0 == y3) {
            cout << x1 + (x2 - x0) << " " << y1 + (y2 - y0) << "\n";
        } else if (x1 == x2 && y1 == y2) {
            cout << x0 + (x3 - x1) << " " << y0 + (y3 - y1) << "\n";
        } else {
            cout << x0 + (x2 - x1) << " " << y0 + (y2 - y1) << "\n";
        }
    }
}
