/**
 *    author:  MaGnsi0
 *    created: 23.12.2023 16:36:30
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            int y; cin >> y;
            count |= (x < 0) * 1;
            count |= (x > 0) * 2;
            count |= (y < 0) * 4;
            count |= (y > 0) * 8;
        }
        cout << (__builtin_popcount(count) <= 3 ? "YES" : "NO") << "\n";
    }
}
