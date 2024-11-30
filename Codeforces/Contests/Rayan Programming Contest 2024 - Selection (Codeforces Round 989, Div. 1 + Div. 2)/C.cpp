/**
 *    author:  MaGnsi0
 *    created: 30.11.2024 17:27:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        int qs = 0;
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            qs += count(a[i].begin(), a[i].end(), '?');
        }
        if (n == 1 && m == 1) {
            cout << 0 << "\n";
            continue;
        }
        if (qs == n * m) {
            cout << n * m << "\n";
            continue;
        }
        vector good(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] != '?') { continue; }
                if (i && good[i - 1][j]) {
                    a[i][j] = 'U';
                    good[i][j] = true;
                } else if (j && good[i][j - 1]) {
                    a[i][j] = 'L';
                    good[i][j] = true;
                } else if (i + 1 < n && a[i + 1][j] == '?') {
                    a[i][j] = 'D'; a[i + 1][j] = 'U';
                    good[i][j] = good[i + 1][j] = true;
                } else if (j + 1 < m && a[i][j + 1] == '?') {
                    a[i][j] = 'R'; a[i][j + 1] = 'L';
                    good[i][j] = good[i][j + 1] = true;
                }

            }
        }
        vector visited(n, vector<int>(m, 0));
        function<bool(int, int)> dfs = [&](int i, int j) {
            visited[i][j] = 1;
            int ni = i + (a[i][j] == 'D') - (a[i][j] == 'U');
            int nj = j + (a[i][j] == 'R') - (a[i][j] == 'L');
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
                good[i][j] = false;
            } else if (a[ni][nj] == '?') {
                good[i][j] = true;
            } else if (visited[ni][nj] == 0) {
                good[i][j] = dfs(ni, nj);
            } else if (visited[ni][nj] == 1) {
                good[i][j] = true;
            } else if (visited[ni][nj] == 2) {
                good[i][j] = good[ni][nj];
            }
            visited[i][j] = 2;
            return good[i][j];
        };
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (visited[i][j] != 0 || a[i][j] == '?') {
                    continue;
                }
                dfs(i, j);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == '?') {
                    ans += (i && good[i - 1][j]) || (j && good[i][j - 1]) || (i + 1 < n && good[i + 1][j]) || (j + 1 < m && good[i][j + 1]);
                } else {
                    ans += good[i][j];
                }
            }
        }
        cout << ans << "\n";
    }
}
