/**
 *    author:  MaGnsi0
 *    created: 11.10.2023 22:12:55
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 3e3;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int n, m, dfsTime = 0;
char a[N][N];

int in[N][N], low[N][N], bridges[N][N];

bool visited[N][N];

void dfs(int x, int y, int px, int py) {
    visited[x][y] = true;
    in[x][y] = low[x][y] = dfsTime++;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || nx > n) { continue; }
        if (ny < 1 || ny > m) { continue; }
        if (a[nx][ny] == '#') { continue; }
        if (nx == px && ny == py) { continue; }
        if (visited[nx][ny]) {
            low[x][y] = min(low[x][y], in[nx][ny]);
        } else {
            dfs(nx, ny, x, y);
            low[x][y] = min(low[x][y], low[nx][ny]);
            if (in[x][y] <= low[nx][ny]) {
                bridges[x][y]++;
                bridges[nx][ny]++;
            }
        }
    }
}

void dfs_(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || nx > n) { continue; }
        if (ny < 1 || ny > m) { continue; }
        if (a[nx][ny] == '#') { continue; }
        if (visited[nx][ny]) { continue; }
        dfs_(nx, ny);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(bridges, 0, sizeof bridges);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    memset(visited, 0, sizeof visited);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (visited[i][j]) { continue; }
            if (a[i][j] == '#') { continue; }
            dfs(i, j, -1, -1);
        }
    }
    int X = -1, Y = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] == '#') { continue; }
            if (X == -1 || bridges[i][j] > bridges[X][Y]) {
                X = i, Y = j;
            }
        }
    }
    a[X][Y] = '#';
    int ans = 0;
    memset(visited, 0, sizeof visited);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] == '#') { continue; }
            if (visited[i][j]) { continue; }
            dfs_(i, j);
            ans++;
        }
    }
    cout << ans;
}
