/**
 *    author:  MaGnsi0
 *    created: 28.10.2024 17:36:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int x; cin >> x;
        int y; cin >> y;
        int k; cin >> k;
        int j = min(x, y);
        cout << 0 << " " << 0 << " " << j << " " << j << "\n";
        cout << 0 << " " << j << " " << j << " " << 0 << "\n";
    }
}
