/**
 *    author:  MaGnsi0
 *    created: 25.07.2024 15:17:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    queue<int> X, Y;
    vector<vector<int>> res(n, vector<int>(m, -1));
    function<pair<int, int>(int, int, int)> move = [&](int x, int y, int steps) {
        if (steps < 0) {
            if (y + steps >= 0) {
                return make_pair(x, y + steps);
            }
            return make_pair(x - 1, m - (x == 0) - 1);
        }
        if (y + steps < m) {
            return make_pair(x, y + steps);
        }
        int nx = x + 1, ny = 0, nsteps = steps - (m - y);
        int dx = nsteps / m, dy = nsteps % m;
        return make_pair(nx + dx, ny + dy);
    };
    function<bool(int, int)> good = [&](int x, int y) {
        if (x < 0 || x >= n) { return false; }
        if (y < 0 || y >= m) { return false; }
        if (res[x][y] != -1) { return false; }
        return true;
    };
    res[0][0] = 0, X.push(0), Y.push(0);
    while (!X.empty()) {
        int x = X.front(); X.pop();
        int y = Y.front(); Y.pop();
        if (a[x][y] == '.') {
            int nx, ny;
            tie(nx, ny) = move(x, y, 1);
            if (good(nx, ny)) {
                res[nx][ny] = res[x][y] + 1;
                X.push(nx), Y.push(ny);
            }
        } else if (a[x][y] == '#') {
            int nx, ny;
            tie(nx, ny) = move(x, y, -2);
            if (good(nx, ny)) {
                res[nx][ny] = res[x][y] + 1;
                X.push(nx), Y.push(ny);
            }
        } else {
            int nx, ny;
            tie(nx, ny) = move(x, y, a[x][y] - '0');
            if (good(nx, ny)) {
                res[nx][ny] = res[x][y] + 1;
                X.push(nx), Y.push(ny);
            }
            tie(nx, ny) = move(x, y, 1);
            if (good(nx, ny)) {
                res[nx][ny] = res[x][y] + 1;
                X.push(nx), Y.push(ny);
            }
        }
    }
    cout << res[n - 1][m - 1];
}
