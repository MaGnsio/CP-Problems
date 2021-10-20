/**
 *    author:  MaGnsi0
 *    created: 17/09/2021 22:44:07
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int h, w;
    cin >> h >> w;
    vector<vector<int>> v(h + 2, vector<int>(w + 2));
    for (int i = 0; i < h + 2; ++i) {
        for (int j = 0; j < w + 2; ++j) {
            cin >> v[i][j];
        }
    }
    vector<vector<char>> g(h + 1, vector<char>(w + 1, '.'));
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
            int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
            bool ok = true;
            for (int k = 0; k < 9; ++k) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x < 0 || x >= h + 2) {
                    continue;
                }
                if (y < 0 || y >= w + 2) {
                    continue;
                }
                if (!v[x][y]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                g[i][j] = 'X';
                for (int k = 0; k < 9; ++k) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x < 0 || x >= h + 2) {
                        continue;
                    }
                    if (y < 0 || y >= w + 2) {
                        continue;
                    }
                    v[x][y]--;
                }
            }
        }
    }
    for (int i = 0; i < h + 2; ++i) {
        for (int j = 0; j < w + 2; ++j) {
            if (v[i][j]) {
                cout << "impossible";
                return 0;
            }
        }
    }
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            cout << g[i][j];
        }
        cout << "\n";
    }
}
