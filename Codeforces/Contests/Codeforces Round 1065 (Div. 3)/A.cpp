/**
 *    author:  MaGnsi0
 *    created: 20.11.2025 16:40:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            ans += (i % 2 == 0) && ((n - i) % 4 == 0);
        }
        cout << ans << "\n";
    }
}
