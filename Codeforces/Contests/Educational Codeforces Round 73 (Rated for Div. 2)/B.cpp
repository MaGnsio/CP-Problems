/**
 *    author:  MaGnsi0
 *    created: 18.10.2023 21:55:12
**/
#include <bits/stdc++.h>

using namespace std;

const int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<char>> ans(n, vector<char>(n, '*'));
    function<void(int, int, char)> dfs = [&](int x, int y, char c) {
        ans[x][y] = c;
        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n) { continue; }
            if (ny < 0 || ny >= n) { continue; }
            if (ans[nx][ny] != '*') { continue; }
            dfs(nx, ny, (c == 'W' ? 'B' : 'W'));
        }
    };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (ans[i][j] == '*') {
                dfs(i, j, 'W');
            }
            cout << ans[i][j];
        }
        cout << "\n";
    }
}
