/**
 *    author:  MaGnsi0
 *    created: 15.12.2024 17:38:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int m, a, b, c;
        cin >> m >> a >> b >> c;
        a = min(a, m); b = min(b, m);
        c = min(2 * m - a - b, c);
        cout << a + b + c << "\n";
    }
}
