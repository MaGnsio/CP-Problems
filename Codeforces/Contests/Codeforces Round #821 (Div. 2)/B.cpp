/**
 *    author:  MaGnsi0
 *    created: 19.09.2022 16:32:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, x, y;
        cin >> n >> x >> y;
        if (x && y) {
            cout << -1 << "\n";
            continue;
        }
        if (x == y) {
            cout << -1 << "\n";
            continue;
        }
        if (x < y) { swap(x, y); }
        if ((n - 1) % x == 0) {
            for (int i = 0; i < (n - 1) / x; ++i) {
                for (int j = 0; j < x; ++j) {
                    cout << (i * x) + 2 << " ";
                }
            }
            cout << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}
