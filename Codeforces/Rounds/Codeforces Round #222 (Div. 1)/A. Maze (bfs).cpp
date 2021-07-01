/**
 *    author:  MaGnsi0
 *    created: 10/06/2021 15:27:25
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, k, r, c, cnt = 0;
    cin >> n >> m >> k;
    vector<vector<char>> g(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
            if (g[i][j] == '#') {
                visited[i][j] = true;
            } else {
                cnt++;
                r = i, c = j;
            }
        }
    }
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    queue<int> x, y;
    x.push(r), y.push(c);
    visited[r][c] = true;
    cnt--;
    if (cnt == k) {
        goto check_point;
    }
    while (!x.empty()) {
        r = x.front(), c = y.front();
        x.pop(), y.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = r + dx[i], nc = c + dy[i];
            if (nr < 0 || nr >= n) {
                continue;
            }
            if (nc < 0 || nc >= m) {
                continue;
            }
            if (visited[nr][nc] == true) {
                continue;
            }
            x.push(nr), y.push(nc);
            visited[nr][nc] = true;
            cnt--;
            if (cnt == k) {
                goto check_point;
            }
        }
    }
    check_point:
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '#') {
                cout << g[i][j];
            } else {
                cout << (visited[i][j] ? '.' : 'X');
            }
        }
        cout << "\n";
    }
}
