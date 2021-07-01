/**
 *    author:  MaGnsi0
 *    created: 11/06/2021 20:57:36
**/
#include <bits/stdc++.h>
using namespace std;

void solve(int n, int m) {
    vector<pair<int, int>> v(3);
    for (auto& [x, y] : v) {
        cin >> x >> y;
        x--, y--;
    }
    int g[n][m][3];
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    memset(g, -1, sizeof g);
    for (int i = 0; i < 3; ++i) {
        queue<int> x, y;
        x.push(v[i].first), y.push(v[i].second);
        g[v[i].first][v[i].second][i] = 0;
        while (!x.empty()) {
            int r = x.front(), c = y.front();
            x.pop(), y.pop();
            for (int j = 0; j < 4; ++j) {
                int nr = r + dx[j], nc = c + dy[j];
                if (nr < 0 || nr >= n) {
                    continue;
                }
                if (nc < 0 || nc >= m) {
                    continue;
                }
                if (g[nr][nc][i] != -1) {
                    continue;
                }
                x.push(nr), y.push(nc);
                g[nr][nc][i] = g[r][c][i] + 1;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        if (g[0][i][0] < g[0][i][1] && g[0][i][0] < g[0][i][2]) {
            cout << "YES\n";
            return;
        }
        if (g[n - 1][i][0] < g[n - 1][i][1] && g[n - 1][i][0] < g[n - 1][i][2]) {
            cout << "YES\n";
            return;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (g[i][0][0] < g[i][0][1] && g[i][0][0] < g[i][0][2]) {
            cout << "YES\n";
            return;
        }
        if (g[i][m - 1][0] < g[i][m - 1][1] && g[i][m - 1][0] < g[i][m - 1][2]) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, T;
    cin >> n >> m >> T;
    while (T--) {
        solve(n, m);
    }
}
