/**
 *    author:  MaGnsi0
 *    created: 05/06/2021 20:14:32
**/
#include <bits/stdc++.h>
using namespace std;

void dfs(int n, int m, int k, int s, vector<vector<char>>& g, vector<vector<bool>>& v, int x, int y) {
    static int cc = 0;
    static int dx[] = {-1, 0, 0, 1};
    static int dy[] = {0, -1, 1, 0};
    if (cc == s - k) {
        return;
    }
    v[x][y] = true;
    g[x][y] = '.';
    cc++;
    for (int i = 0; i < 4; ++i) {
        if (x + dx[i] < 0 || x + dx[i] >= n) {
            continue;
        }
        if (y + dy[i] < 0 || y + dy[i] >= m) {
            continue;
        }
        if (v[x + dx[i]][y + dy[i]] || g[x + dx[i]][y + dy[i]] != 'X') {
            continue;
        }
        dfs(n, m, k, s, g, v, x + dx[i], y + dy[i]);
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, k, s = 0;
    cin >> n >> m >> k;
    vector<vector<char>> g(n, vector<char>(m));
    vector<vector<bool>> v(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
            if (g[i][j] == '#') {
                v[i][j] = true;
            } else {
                g[i][j] = 'X';
                s++;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == 'X') {
                dfs(n, m, k, s, g, v, i, j);
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << g[i][j];
        }
        cout << "\n";
    }
}
