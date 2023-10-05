/**
 *    author:  MaGnsi0
 *    created: 22.03.2022 16:38:57
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
        if (!x && !y) {
            cout << 0;
        } else {
            bool ok = false;
            for (int i = 0; i * i <= (x * x) + (y * y); ++i) {
                if ((x * x) + (y * y) == i * i) {
                    ok = true;
                }
            }
            cout << (ok ? 1 : 2);
        }
        cout << "\n";
    }
}
