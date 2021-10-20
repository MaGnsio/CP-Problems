/**
 *    author:  MaGnsi0
 *    created: 13/06/2021 20:24:15
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, t = 0;
    while (cin >> n) {
        int ans = 0;
        vector<vector<char>> g(n, vector<char>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> g[i][j];
            }
        }
        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][j] == '0') {
                    continue;
                }
                queue<int> x, y;
                x.push(i), y.push(j);
                g[i][j] = '0';
                while (!x.empty()) {
                    int r = x.front(), c = y.front();
                    x.pop(), y.pop();
                    for (int k = 0; k < 8; ++k) {
                        int nr = r + dx[k], nc = c + dy[k];
                        if (nr < 0 || nr >= n) {
                            continue;
                        }
                        if (nc < 0 || nc >= n) {
                            continue;
                        }
                        if (g[nr][nc] == '0') {
                            continue;
                        }
                        x.push(nr), y.push(nc);
                        g[nr][nc] = '0';
                    }
                }
                ans++;
            }
        }
        cout << "Image number " << ++t << " contains " << ans << " war eagles.\n";
    }
}
