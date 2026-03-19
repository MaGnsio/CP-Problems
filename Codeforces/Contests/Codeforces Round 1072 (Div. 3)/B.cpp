/**
 *    author:  MaGnsi0
 *    created: 12.01.2026 17:10:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int s; cin >> s;
        int k; cin >> k;
        int m; cin >> m;
        int x = m % k;
        if (k <= s) {
            int f = m / k;
            if (f & 1) {
                cout << k - x << "\n";
            } else {
                cout << s - x << "\n";
            }
        } else {
            cout << max(s - x, 0) << "\n";
        }
    }
}
