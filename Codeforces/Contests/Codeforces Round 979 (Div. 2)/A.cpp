/**
 *    author:  MaGnsi0
 *    created: 19.10.2024 17:06:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int x = 0, y = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int z; cin >> z;
            x = max(x, z);
            y = min(y, z);
        }
        int ans = (n - 1) * (x - y);
        cout << ans << "\n";
    }
}
