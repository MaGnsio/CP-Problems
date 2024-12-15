/**
 *    author:  MaGnsi0
 *    created: 15.12.2024 16:46:40
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int Q; cin >> Q;
        vector a(3, vector(n, vector<int64_t>(n)));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int64_t x; cin >> x;
                a[0][i][j] = (j + 1) * x;
                a[1][i][j] = x;
                a[2][i][j] = i * x;
            }
        }
        for (int k = 0; k < 3; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 1; j < n; ++j) {
                    a[k][i][j] += a[k][i][j - 1];
                }
            }
        }
        for (int k = 0; k < 3; ++k) {
            for (int i = 1; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    a[k][i][j] += a[k][i - 1][j];
                }
            }
        }
        function<int64_t(int, int, int, int, int)> get_sum = [&](int k, int x1, int y1, int x2, int y2) {
            int64_t sum = a[k][x2][y2];
            if (x1) { sum -= a[k][x1 - 1][y2]; }
            if (y1) { sum -= a[k][x2][y1 - 1]; }
            if (x1 && y1) { sum += a[k][x1 - 1][y1 - 1]; }
            return sum;
        };
        while (Q--) {
            int x1; cin >> x1; x1--;
            int y1; cin >> y1; y1--;
            int x2; cin >> x2; x2--;
            int y2; cin >> y2; y2--;
            int64_t C1 = x1 * y1 - x1 * y2 - x1 - y1, C2 = y2 - y1 + 1;
            int64_t ans = get_sum(0, x1, y1, x2, y2) + C1 * get_sum(1, x1, y1, x2, y2) + C2 * get_sum(2, x1, y1, x2, y2);
            cout << ans << " ";
        }
        cout << "\n";
    }
}

