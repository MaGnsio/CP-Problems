/**
 *    author:  MaGnsi0
 *    created: 16.01.2024 16:31:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int minx = INT_MAX, maxx = -INT_MAX;
        for (int i = 0; i < 4; ++i) {
            int x; cin >> x;
            int _; cin >> _;
            minx = min(minx, x);
            maxx = max(maxx, x);
        }
        cout << (maxx - minx) * (maxx - minx) << "\n";
    }
}
