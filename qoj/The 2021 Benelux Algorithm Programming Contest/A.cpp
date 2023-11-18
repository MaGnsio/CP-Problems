/**
 *    author:  MaGnsi0
 *    created: 05.10.2023 16:02:09
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x, y, r;
    cin >> x >> y >> r;
    int x1 = x - r, y1 = y + r;
    int x2 = x + r, y2 = y + r;
    int x3 = x + r, y3 = y - r;
    int x4 = x - r, y4 = y - r;
    cout << x1 << " " << y1 << "\n";
    cout << x2 << " " << y2 << "\n";
    cout << x3 << " " << y3 << "\n";
    cout << x4 << " " << y4 << "\n";
}
