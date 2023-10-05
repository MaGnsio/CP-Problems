/**
 *    author:  MaGnsi0
 *    created: 06.08.2022 16:33:58
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> x(n), y(n);
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
        }
        int max_x = 0, min_x = 0, max_y = 0, min_y = 0;
        for (int i = 0; i < n; ++i) {
            if (y[i] == 0) {
                max_x = max(max_x, x[i]);
                min_x = min(min_x, x[i]);
            }
            if (x[i] == 0) {
                max_y = max(max_y, y[i]);
                min_y = min(min_y, y[i]);
            }
        }
        cout << 2 * (max_x + abs(min_x) + max_y + abs(min_y)) << "\n";
    }
}
