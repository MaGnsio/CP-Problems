/**
 *    author:  MaGnsi0
 *    created: 18.09.2024 21:46:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int l; cin >> l;
        int r; cin >> r;
        int ans = 0;
        for (int i = l; i <= r; ++i) {
            if (i % 2 == 0) { continue; }
            ans += i + 2 <= r; i += 2;
        }
        cout << ans << "\n";
    }
}
