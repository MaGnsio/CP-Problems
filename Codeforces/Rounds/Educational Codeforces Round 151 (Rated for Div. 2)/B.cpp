/**
 *    author:  MaGnsi0
 *    created: 29.06.2023 17:43:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        vector<int> x(3), y(3);
        for (int i = 0; i < 3; ++i) {
            cin >> x[i] >> y[i];
        }
        int ans = 1;
        if (x[0] >= x[1] && x[0] >= x[2]) {
            ans += x[0] - max(x[1], x[2]);
        } else if (x[0] <= x[1] && x[0] <= x[2]) {
            ans += min(x[1], x[2]) - x[0];
        }
        if (y[0] >= y[1] && y[0] >= y[2]) {
            ans += y[0] - max(y[1], y[2]);
        } else if (y[0] <= y[1] && y[0] <= y[2]) {
            ans += min(y[1], y[2]) - y[0];
        }
        cout << ans << "\n";
    }
}
