/**
 *    author:  MaGnsi0
 *    created: 25.01.2026 16:35:18
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int s; cin >> s;
        int x; cin >> x;
        for (int i = 0; i < n; ++i) {
            int y; cin >> y; s -= y;
        }
        cout << (s >= 0 && s % x == 0 ? "YES" : "NO") << "\n";
    }
}
