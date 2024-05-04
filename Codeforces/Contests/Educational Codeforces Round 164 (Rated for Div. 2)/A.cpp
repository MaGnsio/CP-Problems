/**
 *    author:  MaGnsi0
 *    created: 13.04.2024 01:56:40
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        int k; cin >> k;
        if (m == 1 || k >= n - 1) {
            cout << "NO\n";
        } else {
            cout << (m * (n - k - 1) >= n ? "YES" : "NO") << "\n";
        }
    }
}
