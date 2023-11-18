/**
 *    author:  MaGnsi0
 *    created: 03.11.2023 17:27:38
**/
#include <bits/stdc++.h>

using namespace std;

const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j + 1 < m; ++j) {
            if (a[i][j] != '/') { continue; }
            if (a[i][j + 1] != '\\') { continue; }
            if (a[i + 1][j] != '\\') { continue; }
            if (a[i + 1][j + 1] != '/') { continue; }
            ans++;
        }
    }
    bool bounded = true;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    function<void(int, int)> dfs = [&](int x, int y) {
        visited[x][y] = true;
        bounded = bounded && 0 < x && x < n - 1 && 0 < y && y < m - 1;
        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n) { continue; }
            if (ny < 0 || ny >= m) { continue; }
            if (a[nx][ny] != '.') { continue; }
            if (visited[nx][ny]) { continue; }
            if (i == 7 && a[x][y + 1] == '/') { continue; }
            if (i == 5 && a[x][y - 1] == '\\') { continue; }
            if (i == 2 && a[x - 1][y] == '\\') { continue; }
            if (i == 0 && a[x - 1][y] == '/') { continue; }
            dfs(nx, ny);
        }
    };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (visited[i][j]) { continue; }
            if (a[i][j] != '.') { continue; }
            bounded = true;
            dfs(i, j);
            ans += bounded;
        }
    }
    cout << ans;
}
