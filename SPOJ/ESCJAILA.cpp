/**
 *    author:  MaGnsi0
 *    created: 13/06/2021 20:47:34
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m;
    while ((cin >> n >> m) && (n != -1)) {
        int ans = INT_MAX;
        vector<vector<char>> g(n, vector<char>(2 * m));
        vector<vector<int>> d(n, vector<int>(2 * m, -1));
        queue<int> x, y, o;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2 * m; j += 2) {
                cin >> g[i][j];
                if (g[i][j] == 'H') {
                    g[i][j] = '.';
                    x.push(i), y.push(j), o.push(0);
                    d[i][j] = 1;
                }
                g[i][j + 1] = g[i][j];
            }
        }
        int dx[4] = {-1, 0, 0, 1};
        int dy[4] = {0, -2, 2, 0};
        while (!x.empty()) {
            int r = x.front(), c = y.front(), op = o.front();
            x.pop(), y.pop(), o.pop();
            for (int i = 0; i < 4; ++i) {
                int nr = r + dx[i], nc = c + dy[i];
                if (nr < 0 || nr >= n) {
                    ans = min(ans, d[r][c]);
                    continue;
                }
                if (nc < 0 || nc >= 2 * m) {
                    ans = min(ans, d[r][c]);
                    continue;
                }
                if (g[nr][nc] == 'W' || (g[nr][nc] == 'D' && op == 0) || d[nr][nc] != -1) {
                    continue;
                }
                x.push(nr), y.push(nc);
                d[nr][nc] = d[r][c] + 1;
                if (g[nr][nc] == 'O') {
                    if (nc & 1) {
                        x.push(nr), y.push(nc - 1);
                        d[nr][nc - 1] = d[nr][nc];
                    } else {
                        x.push(nr), y.push(nc + 1);
                        d[nr][nc + 1] = d[nr][nc];
                    }
                    o.push(1), o.push(1);
                } else if (g[nr][nc] == 'C') {
                    if (nc & 1) {
                        d[nr][nc - 1] = d[nr][nc];
                    } else {
                        d[nr][nc + 1] = d[nr][nc];
                    }
                    o.push(0);
                } else {
                    o.push(op);
                }
            }
        }
        cout << (ans == INT_MAX ? -1 : ans) << "\n";
    }
}
