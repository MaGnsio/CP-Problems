/**
 *    author:  MaGnsi0
 *    created: 20.09.2024 17:35:53
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
        x = min(x, y);
        cout << (n + x - 1) / x << "\n";
    }
}
