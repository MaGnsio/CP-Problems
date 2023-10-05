/**
 *    author:  MaGnsi0
 *    created: 05/06/2021 21:13:46
**/
#include <bits/stdc++.h>
using namespace std;

int n, m;

char g[1001][1001];
bool v[1001][1001][4][3];

bool dfs(int x, int y, int d, int t) {
    static int dx[] = {-1, 0, 0, 1};
    static int dy[] = {0, -1, 1, 0};
    if (x < 0 || x >= n) {
        return false;
    }
    if (y < 0 || y >= m) {
        return false;
    }
    if (t > 2) {
        return false;
    }
    if (v[x][y][d][t] || g[x][y] == '*') {
        return false;
    }
    if (g[x][y] == 'T') {
        return true;
    }
    v[x][y][d][t] = true;
    bool ok = false;
    for (int i = 0; i < 4; ++i) {
        ok |= dfs(x + dx[i], y + dy[i], i, t + (i == d || d == -1 ? 0 : 1));
    }
    return ok;
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int x, y;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
            if (g[i][j] == 'S') {
                x = i, y = j;
            }
        }
    }
    cout << (dfs(x, y, -1, 0) ? "YES" : "NO");
}
