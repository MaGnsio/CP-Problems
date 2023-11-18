/**
 *    author:  MaGnsi0
 *    created: 10.11.2023 16:41:38
**/
#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        vector<vector<bool>> done(n, vector<bool>(m));
        function<int(int, int)> sum = [&](int x, int y) {
            int res = a[x][y];
            done[x][y] = true;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n) { continue; }
                if (ny < 0 || ny >= m) { continue; }
                if (a[nx][ny] == 0) { continue; }
                if (done[nx][ny]) { continue; }
                res += sum(nx, ny);
            }
            return res;
        };
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 0) { continue; }
                if (done[i][j]) { continue; }
                ans = max(ans, sum(i, j));
            }
        }
        cout << ans << "\n";
    }
}
