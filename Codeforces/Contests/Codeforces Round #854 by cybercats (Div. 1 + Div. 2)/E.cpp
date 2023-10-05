/**
 *    author:  MaGnsi0
 *    created: 27.02.2023 18:38:30
**/
#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (int i = 0; i < n; ++i) { cin >> a[i]; }
        function<void()> fill = [&]() {
            while (true) {
                bool stop = true;
                for (int i = 0; i < n; ++i) {
                    int L = m + 1, R = -1;
                    for (int j = 0; j < m; ++j) {
                        if (a[i][j] == '#') {
                            L = min(L, j), R = max(R, j);
                        }
                    }
                    for (int j = L; j <= R; ++j) {
                        if (a[i][j] == '.') { stop = false; }
                        a[i][j] = '#';
                    }
                }
                for (int j = 0; j < m; ++j) {
                    int L = n + 1, R = -1;
                    for (int i = 0; i < n; ++i) {
                        if (a[i][j] == '#') {
                            L = min(L, i), R = max(R, i);
                        }
                    }
                    for (int i = L; i <= R; ++i) {
                        if (a[i][j] == '.') { stop = false; }
                        a[i][j] = '#';
                    }
                }
                if (stop) { return; }
            }
        };
        function<void(int, int, int, int)> connect = [&](int x1, int y1, int x2, int y2) {
            while (x1 != x2) {
                a[x1][y1] = '#';
                if (x1 < x2) { x1++; }
                if (x1 > x2) { x1--; }
            }
            while (y1 != y2) {
                a[x1][y1] = '#';
                if (y1 < y2) { y1++; }
                if (y1 > y2) { y1--; }
            }
        };
        fill();
        int components = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<int> min_x, max_x, min_y, max_y;
        function<void(int, int)> dfs = [&](int x, int y) {
            visited[x][y] = true;
            min_x.back() = min(min_x.back(), x);
            max_x.back() = max(max_x.back(), x);
            min_y.back() = min(min_y.back(), y);
            max_y.back() = max(max_y.back(), y);
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 0 || nx >= n) { continue; }
                if (ny < 0 || ny >= m) { continue; }
                if (a[nx][ny] == '.') { continue; }
                if (visited[nx][ny]) { continue; }
                dfs(nx, ny);
            }
        };
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] != '#' || visited[i][j]) { continue; }
                min_x.push_back(i), max_x.push_back(i);
                min_y.push_back(j), max_y.push_back(j);
                dfs(i, j);
                components++;
            }
        }
        if (components > 1) {
            assert(components == 2);
            int u = 0, v = 1;
            if (max_x[u] > min_x[v]) { swap(u, v); }
            if (max_y[u] < min_y[v]) {
                int x1 = max_x[u], y1 = max_y[u];
                int x2 = min_x[v], y2 = min_y[v];
                connect(x1, y1, x2, y2);
            } else {
                int x1 = max_x[u], y1 = min_y[u];
                int x2 = min_x[v], y2 = max_y[v];
                connect(x1, y1, x2, y2);
            }
        }
        fill();
        for (int i = 0; i < n; ++i) {
            cout << a[i] << "\n";
        }
        cout << "\n";
    }
}
