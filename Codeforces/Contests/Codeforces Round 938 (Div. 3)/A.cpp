/**
 *    author:  MaGnsi0
 *    created: 11.04.2024 18:20:35
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
        cout << min(y, 2 * x) * (n / 2) + x * (n % 2) << "\n";
    }
}
