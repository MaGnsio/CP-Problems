/**
 *    author:  MaGnsi0
 *    created: 20.10.2022 16:36:42
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; ++i) {
            int _x, _y;
            cin >> _x >> _y;
        }
        cout << (m < n ? "YES" : "NO") << "\n";
    }
}
