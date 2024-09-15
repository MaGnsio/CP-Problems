/**
 *    author:  MaGnsi0
 *    created: 06.01.2024 14:11:38
**/
#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<vector<int>> ans(n, vector<int>(n, -1));
    function<bool(int, int)> bad = [&](int x, int y) {
        if (x < 0 || x >= n) { return true; }
        if (y < 0 || y >= n) { return true; }
        if (ans[x][y] != -1) { return true; }
        return false;
    };
    ans[n / 2][n / 2] = 0;
    int x = 0, y = 0, part = 1, way = 0;
    while (true) {
        if (bad(x, y)) { break; }
        if (ans[x][y] != -1) { break; }
        ans[x][y] = part++;
        int nx = x + dx[way];
        int ny = y + dy[way];
        if (bad(nx, ny)) { way++; way %= 4; }
        x += dx[way];
        y += dy[way];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (ans[i][j] != 0) {
                cout << ans[i][j] << " ";
            } else {
                cout << "T ";
            }
        }
        cout << "\n";
    }
}
