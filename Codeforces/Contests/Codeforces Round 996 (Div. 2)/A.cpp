/**
 *    author:  MaGnsi0
 *    created: 12.01.2025 16:36:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int x; cin >> x;
        int y; cin >> y;
        cout << ((x & 1) == (y & 1) ? "YES" : "NO") << "\n";
    }
}
