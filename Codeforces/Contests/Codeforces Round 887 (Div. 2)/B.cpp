/**
 *    author:  MaGnsi0
 *    created: 07.01.2024 17:02:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        int ans = 0;
        if (k == 1) {
            cout << 1 << "\n";
            continue;
        }
        for (int x = 1; x <= n; ++x) {
            int y = n, z = x, m = 2;
            while (true) {
                if (y < 0 || z < 0 || y < z) { break; }
                if (m == k || (y == 0 && z == 0)) {
                    ans++;
                    break;
                }
                int t = y;
                y = z, z = t - z, m++;
            }
        }
        cout << ans << "\n";
    }
}
