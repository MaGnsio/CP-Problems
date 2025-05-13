/**
 *    author:  MaGnsi0
 *    created: 13.05.2025 19:28:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        int p; cin >> p;
        int q; cin >> q;
        int r = n % p;
        if (r == 0) {
            cout << (q * (n / p) == m ? "YES" : "NO") << "\n";
        } else {
            cout << "YES" << "\n";
        }
    }
}
