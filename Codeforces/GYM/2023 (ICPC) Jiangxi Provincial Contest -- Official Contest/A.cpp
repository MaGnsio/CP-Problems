/**
 *    author:  MaGnsi0
 *    created: 10.11.2023 18:22:35
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
        cout << (x * y >= n ? 1 : 0) << "\n";
    }
}
