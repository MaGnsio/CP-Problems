/**
 *    author:  MaGnsi0
 *    created: 27.02.2025 16:35:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m = (n % 15), ans = 0;
        if (n == 0) {
            ans = 1;
        } else if (n == 1) {
            ans = 2;
        } else if (n == 2) {
            ans = 3;
        } else if (m == 0) {
            ans = 3 * (n / 15) + 1;
        } else if (m == 1) {
            ans = 3 * (n / 15) + 2;
        } else {
            ans = 3 * (n / 15) + 3;
        }
        cout << ans << "\n";
    }
}
