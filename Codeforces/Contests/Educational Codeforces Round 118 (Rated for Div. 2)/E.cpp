/**
 *    author:  MaGnsi0
 *    created: 01.12.2021 16:24:12
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> g(n, vector<char>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> g[i][j];
            }
        }
        int x, y;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (g[i][j] == 'L') {
                    x = i, y = j;
                }
            }
        }
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<int> X, Y;
        X.push(x), Y.push(y);
        visited[x][y] = true;
        while (!X.empty()) {
            int r = X.front(), c = Y.front();
            X.pop(), Y.pop();
            int dx[4] = {-1, 0, 0, 1};
            int dy[4] = {0, -1, 1, 0};
            for (int i = 0; i < 4; ++i) {
                int nr = r + dx[i];
                int nc = c + dy[i];
                if (nr < 0 || nr >= n) {
                    continue;
                }
                if (nc < 0 || nc >= m) {
                    continue;
                }
                if (visited[nr][nc] || g[nr][nc] == '#') {
                    continue;
                }
                int can = 0;
                for (int j = 0; j < 4; ++j) {
                    int nnr = nr + dx[j];
                    int nnc = nc + dy[j];
                    if (nnr < 0 || nnr >= n) {
                        continue;
                    }
                    if (nnc < 0 || nnc >= m) {
                        continue;
                    }
                    if (g[nnr][nnc] == '.') {
                        can++;
                    }
                }
                if (can <= 1) {
                    X.push(nr), Y.push(nc);
                    visited[nr][nc] = true;
                    g[nr][nc] = '+';
                }
            }
        }
        g[x][y] = 'L';
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << g[i][j];
            }
            cout << "\n";
        }
    }
}
