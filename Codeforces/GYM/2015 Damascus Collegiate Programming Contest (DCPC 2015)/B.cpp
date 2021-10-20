/**
 *    author:  MaGnsi0
 *    created: 04/08/2021 05:15:23
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int minx = INT_MAX, miny = INT_MAX, maxx = INT_MIN, maxy = INT_MIN;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 4; ++j) {
                int x, y;
                cin >> x >> y;
                minx = min(minx, x);
                maxx = max(maxx, x);
                miny = min(miny, y);
                maxy = max(maxy, y);
            }
        }
        cout << (maxx - minx) * (maxy - miny) << "\n";
    }
}
