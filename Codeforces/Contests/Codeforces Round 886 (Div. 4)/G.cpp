/**
 *    author:  MaGnsi0
 *    created: 21.07.2023 18:07:15
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
        map<int, int64_t> x, y, dx, dy;
        for (int i = 0; i < n; ++i) {
            int X, Y;
            cin >> X >> Y;
            x[X]++;
            y[Y]++;
            dx[X - Y]++;
            dy[Y + X]++;
        }
        int64_t ans = 0;
        for (auto [_, val] : x) {
            ans += val * (val - 1);
        }
        for (auto [_, val] : y) {
            ans += val * (val - 1);
        }
        for (auto [_, val] : dx) {
            ans += val * (val - 1);
        }
        for (auto [_, val] : dy) {
            ans += val * (val - 1);
        }
        cout << ans << "\n";
    }
}
