/**
 *    author:  MaGnsi0
 *    created: 13.09.2024 20:19:31
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        cout << (n >= m && (n - m) % 2 == 0 ? "YES" : "NO") << "\n";
    }
}
