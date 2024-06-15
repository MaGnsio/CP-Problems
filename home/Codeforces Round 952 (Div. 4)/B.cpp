/**
 *    author:  MaGnsi0
 *    created: 15.06.2024 18:22:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int ans = 2, sum = 0;
        for (int x = 2; x <= n; ++x) {
            int y = x, val = 0;
            while (y <= n) { val += y, y += x; }
            if (val > sum) {
                ans = x;
                sum = val;
            }
        }
        cout << ans << "\n";
    }
}
