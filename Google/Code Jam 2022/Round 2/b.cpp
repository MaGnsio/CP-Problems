/**
 *    author:  MaGnsi0
 *    created: 14.05.2022 17:06:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int R;
        cin >> R;
        vector<vector<char>> a(2 * R + 1, vector<char>(2 * R  + 1, '.'));
        for (int x = -R; x <= R; ++x) {
            for (int y = -R; y <= R; ++y) {
                if (round(sqrt(1.0 * x * x + 1.0 * y * y)) <= R) {
                    a[x + R][y + R] = '*';
                }
            }
        }
        vector<vector<char>> b(2 * R + 1, vector<char>(2 * R  + 1, '.'));
        for (int r = 0; r <= R; ++r) {
            for (int x = -r; x <= r; ++x) {
                int y = round(sqrt(1.0 * r * r - 1.0 * x * x));
                b[x + R][y + R] = b[x + R][-y + R] = b[y + R][x + R] = b[-y + R][x + R] = '*';
            }
        }
        int ans = 0;
        for (int i = 0; i < 2 * R + 1; ++i) {
            for (int j = 0; j < 2 * R + 1; ++j) {
                ans += (a[i][j] != b[i][j]);
            }
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
}
