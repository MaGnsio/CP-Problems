/**
 *    author:  MaGnsi0
 *    created: 13/06/2021 17:21:29
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int h, w, ans = 0;
    cin >> h >> w;
    vector<vector<char>> g(h, vector<char>(w));
    vector<vector<int>> d(h, vector<int>(w, -1));
    queue<int> x, y;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> g[i][j];
            if (g[i][j] == '#') {
                x.push(i), y.push(j);
                d[i][j] = 0;
            }
        }
    }
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    while (!x.empty()) {
        int r = x.front(), c = y.front();
        x.pop(), y.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = r + dx[i], nc = c + dy[i];
            if (nr < 0 || nr >= h) {
                continue;
            }
            if (nc < 0 || nc >= w) {
                continue;
            }
            if (d[nr][nc] != -1) {
                continue;
            }
            x.push(nr), y.push(nc);
            d[nr][nc] = ans = d[r][c] + 1;
        }
    }
    cout << ans;
}
