/**
 *    author:  MaGnsi0
 *    created: 24.01.2022 22:24:40
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int l, r, k;
        cin >> l >> r >> k;
        if (r - l + 1 == 1) {
            cout << (l != 1 ? "YES" : "NO") << "\n";
            continue;
        }
        int x = (r - l + 1) / 2 + (r - l + 1) % 2 * !!(l & 1);
        cout << (x <= k ? "YES" : "NO") << "\n";
    }
}
