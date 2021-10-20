/**
 *    author:  MaGnsi0
 *    created: 01/08/2021 16:31:34
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, res = 0;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    vector<vector<bool>> v(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }
    auto hz = [=] (char c) {
        return (c == '<' || c == '>');
    };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[i][j]) {
                continue;
            }
            int x = i, y = j, cur = 0, cnt = 0;
            if (hz(g[i][j])) {
                while (y < m && hz(g[x][y])) {
                    v[x][y] = true;
                    if (g[x][y] == '<') {
                        cur += cnt;
                    } else {
                        cnt++;
                    }
                    y++;
                }
            } else {
                while (x < n && !hz(g[x][y])) {
                    v[x][y] = true;
                    if (g[x][y] == '^') {
                        cur += cnt;
                    } else {
                        cnt++;
                    }
                    x++;
                }
            }
            res += cur;
        }
    }
    cout << res;
}
