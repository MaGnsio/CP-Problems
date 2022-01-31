/**
 *    author:  MaGnsi0
 *    created: 24.01.2022 22:24:42
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
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        vector<vector<bool>> done(n, vector<bool>(n));
        auto ok = [&](int i, int j) {
            int dx[] = {-1, 0, 0, 1};
            int dy[] = {0, -1, 1, 0};
            for (int k = 0; k < 4; ++k) {
                if (i + dx[k] < 0 || i + dx[k] >= n) {
                    continue;
                }
                if (j + dy[k] < 0 || j + dy[k] >= n) {
                    continue;
                }
                if (done[i + dx[k]][j + dy[k]]) {
                    return false;
                }
            }
            for (int k = 0; k < 4; ++k) {
                if (i + dx[k] < 0 || i + dx[k] >= n) {
                    continue;
                }
                if (j + dy[k] < 0 || j + dy[k] >= n) {
                    continue;
                }
                done[i + dx[k]][j + dy[k]] = true;
            }
            return true;
        };
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (ok(i, j)) {
                    res ^= a[i][j];
                }
            }
        }
        cout << res << "\n";
    }
}
