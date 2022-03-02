/**
 *    author:  MaGnsi0
 *    created: 16.02.2022 07:15:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    cout << "INTERSECTING LINES OUTPUT\n";
    while (T--) {
        int x1, y1, x2, y2;
        int x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2
            >> x3 >> y3 >> x4 >> y4;
        int a1 = y2 - y1;
        int b1 = x1 - x2;
        int c1 = -(a1 * x1 + b1 * y1);
        int a2 = y4 - y3;
        int b2 = x3 - x4;
        int c2 = -(a2 * x3 + b2 * y3);
        if (a1 * b2 - b1 * a2 == 0) {
            if (b1 * c2 - b2 * c1 || a2 * c1 - a1 * c2) {
                cout << "NONE\n";
            } else {
                cout << "LINE\n";
            }
        } else {
            int x = b1 * c2 - b2 * c1;
            int y = a2 * c1 - a1 * c2;
            int m = a1 * b2 - a2 * b1;
            cout << fixed << setprecision(2)
                 << "POINT " << (double)x / m << " " << (double)y / m << "\n";
        }
    }
    cout << "END OF OUTPUT\n";
}
