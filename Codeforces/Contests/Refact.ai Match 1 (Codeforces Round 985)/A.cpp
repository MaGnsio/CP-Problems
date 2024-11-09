/**
 *    author:  MaGnsi0
 *    created: 09.11.2024 22:53:59
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int l; cin >> l;
        int r; cin >> r;
        int k; cin >> k;
        int ans = max(r / k, l - 1) - l + 1;
        cout << ans << "\n";
    }
}
