/**
 *    author:  MaGnsi0
 *    created: 09/06/2021 22:59:56
**/
#include <bits/stdc++.h>
using namespace std;

void bfs(int& n, int& m, vector<vector<char>>& g, vector<vector<int>>& c, int i, int j) {
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<int> x, y;
    visited[i][j] = true;
    x.push(i), y.push(j);
    while (!x.empty()) {
        int vx = x.front(), vy = y.front();
        x.pop(), y.pop();
        for (int k = 0; k < 4; ++k) {
            int ux = vx + dx[k], uy = vy + dy[k];
            if (ux < 0 || ux >= n) {
                continue;
            }
            if (uy < 0 || uy >= m) {
                continue;
            }
            if (visited[ux][uy] || g[ux][uy] == '1') {
                continue;
            }
            visited[ux][uy] = true;
            x.push(ux), y.push(uy);
            c[ux][uy] = min(c[ux][uy], abs(ux - i) + abs(uy - j));
        }
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> g(n, vector<char>(m));
        vector<vector<int>> c(n, vector<int>(m, INT_MAX));
        queue<int> x, y;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> g[i][j];
                if (g[i][j] == '1') {
                    c[i][j] = 0;
                    x.push(i), y.push(j);
                }
            }
        }
        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};
        while (!x.empty()) {
            int vx = x.front(), vy = y.front();
            x.pop(), y.pop();
            for (int i = 0; i < 4; ++i) {
                int ux = vx + dx[i], uy = vy + dy[i];
                if (ux < 0 || ux >= n) {
                    continue;
                }
                if (uy < 0 || uy >= m) {
                    continue;
                }
                if (c[ux][uy] != INT_MAX) {
                    continue;
                }
                c[ux][uy] = c[vx][vy] + 1;
                x.push(ux), y.push(uy);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << c[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
