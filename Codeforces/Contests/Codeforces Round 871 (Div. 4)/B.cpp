/**
 *    author:  MaGnsi0
 *    created: 10.11.2023 16:31:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int ans = 0, x = 0;
        for (int i = 0; i < n; ++i) {
            int c; cin >> c;
            if (c) {
                ans = max(ans, x);
                x = 0;
            } else {
                x++;
            }
        }
        ans = max(ans, x);
        cout << ans << "\n";
    }
}
