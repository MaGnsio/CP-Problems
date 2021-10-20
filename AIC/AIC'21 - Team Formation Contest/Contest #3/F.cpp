/**
 *    author:  MaGnsi0
 *    created: 18/07/2021 13:22:54
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int x1, y1, x2, y2, a, b;
    cin >> x1 >> y1 >> x2 >> y2 >> a >> b;
    if (abs(x1 - x2) % a || abs(y1 - y2) % b) {
        cout << "NO";
        return 0;
    }
    int s1 = abs(x1 - x2) / a, s2 = abs(y1 - y2) / b;
    if (abs(s1 - s2) % 2 == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
