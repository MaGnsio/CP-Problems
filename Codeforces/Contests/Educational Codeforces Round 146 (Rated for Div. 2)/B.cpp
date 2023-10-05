/**
 *    author:  MaGnsi0
 *    created: 16.04.2023 04:44:23
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
        int ans = x + y;
        for (int i = 1; i <= 500000; ++i) {
            ans = min(ans, (x + i - 1) / i + (y + i - 1) / i + i - 1);
        }
        cout << ans << "\n";
    }
}
