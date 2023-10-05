/**
 *    author:  MaGnsi0
 *    created: 20.03.2023 07:21:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, x, y, d;
        cin >> n >> m >> x >> y >> d;
        if (x - 1 <= d && n - x <= d) {
            cout << "-1\n";
        } else if (y - 1 <= d && m - y <= d) {
            cout << "-1\n";
        } else if (x - 1 <= d && y - 1 <= d) {
            cout << "-1\n";
        } else if (n - x <= d && m - y <= d) {
            cout << "-1\n";
        } else {
            cout << n + m - 2 << "\n";
        }
    }
}
