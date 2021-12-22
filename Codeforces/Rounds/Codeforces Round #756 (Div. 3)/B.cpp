/**
 *    author:  MaGnsi0
 *    created: 25.11.2021 16:25:42
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        int l = 0, r = (a + b) / 4, res = 0;
        while (l <= r) {
            int m = (l + r) / 2;
            if (m <= a && m <= b && 4 * m <= a + b) {
                res = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        cout << res << "\n";
    }
}
