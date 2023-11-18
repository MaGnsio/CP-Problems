/**
 *    author:  MaGnsi0
 *    created: 21.10.2023 20:04:15
**/
#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("A1.in", "r", stdin);
    freopen("A1.out", "w", stdout);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n; cin >> n;
        int m; cin >> m;
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int comp_size;
        pair<int, int> good_add;
        vector<vector<int>> add(n, vector<int>(m));
        vector<vector<bool>> visited(n, vector<bool>(m));
        function<void(int, int)> dfs = [&](int x, int y) {
            visited[x][y] = true; comp_size++;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n) { continue; }
                if (ny < 0 || ny >= m) { continue; }
                if (a[nx][ny] == 'B') { continue; }
                if (visited[nx][ny]) { continue; }
                if (a[nx][ny] == '.') {
                    if (good_add == make_pair(nx, ny)) { continue; }
                    if (good_add == make_pair(-2, -2)) { continue; }
                    if (good_add == make_pair(-1, -1)) {
                        good_add = make_pair(nx, ny);
                    } else {
                        good_add = make_pair(-2, -2);
                    }
                    continue;
                }
                dfs(nx, ny);
            }
        };
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] != 'W') { continue; }
                if (visited[i][j]) { continue; }
                comp_size = 0;
                good_add = make_pair(-1, -1);
                dfs(i, j);
                if (good_add.first >= 0) {
                    add[good_add.first][good_add.second] += comp_size;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans = max(ans, add[i][j]);
            }
        }
        cout << "Case #" << t << ": " << (ans ? "YES" : "NO") << "\n";
    }
}
