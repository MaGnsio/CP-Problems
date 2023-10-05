/**
 *    author:  MaGnsi0
 *    created: 28/09/2021 16:19:16
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<char>> g(n + 2, vector<char>(m + 2, '.'));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> g[i][j];
            }
        }
        vector<vector<bool>> v(n + 2, vector<bool>(m + 2, false));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (g[i][j] == '.') {
                    continue;
                }
                int max_d = 0;
                for (int h = 1; i - h >= 1; ++h) {
                    if (g[i - h][j - h] == '*' && g[i - h][j + h] == '*') {
                        max_d++;
                        continue;
                    }
                    break;
                }
                if (max_d >= k) {
                    for (int h = 0; h <= max_d; ++h) {
                        v[i - h][j - h] = v[i - h][j + h] = true;
                    }
                }
            }
        }
        bool ok = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (g[i][j] == '*' && v[i][j] == false) {
                    ok = false;
                }
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
