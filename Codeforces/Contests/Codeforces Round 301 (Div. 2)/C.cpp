/**
 *    author:  MaGnsi0
 *    created: 01.01.2024 21:11:37
**/
#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int sx, sy; cin >> sx >> sy; sx--, sy--;
    int ex, ey; cin >> ex >> ey; ex--, ey--;
    function<void(int, int)> dfs = [&](int x, int y) {
        a[x][y] = '#';
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n) { continue; }
            if (ny < 0 || ny >= m) { continue; }
            if (a[nx][ny] != '.' && !(nx == ex && ny == ey)) { continue; }
            dfs(nx, ny);
        }
    };
    int ends = 2 * (a[ex][ey] == 'X');
    for (int i = 0; i < 4; ++i) {
        int nx = ex + dx[i];
        int ny = ey + dy[i];
        if (nx < 0 || nx >= n) { continue; }
        if (ny < 0 || ny >= m) { continue; }
        ends += a[nx][ny] == '.';
        ends += nx == sx && ny == sy;
    }
    if (sx == ex && sy == ey) {
        cout << (ends - 2 ? "YES" : "NO");
        return 0;
    }
    dfs(sx, sy);
    cout << (a[ex][ey] == '#' && ends > 1 ? "YES" : "NO");
}
