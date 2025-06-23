/**
 *    author:  MaGnsi0
 *    created: 23.06.2025 17:36:02
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int a; cin >> a;
        int x; cin >> x;
        int y; cin >> y;
        bool ok = false;
        for (int b = 1; b <= 100; ++b) {
            ok |= (abs(b - x) < abs(a - x)) && (abs(b - y) < abs(a - y));
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
