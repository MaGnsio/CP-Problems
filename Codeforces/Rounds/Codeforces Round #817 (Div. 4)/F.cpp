/**
 *    author:  MaGnsi0
 *    created: 30.08.2022 16:34:15
**/
#include <bits/stdc++.h>

using namespace std;

const int dx[8] = {-1, 0 ,0, 1, -1, -1, 1, 1};
const int dy[8] = {0, -1, 1, 0, -1, 1, -1, 1};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        bool ok = true;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        function<int(int, int)> bfs = [&](int i, int j) {
            int sz = 1;
            queue<int> X, Y;
            X.push(i), Y.push(j);
            visited[i][j] = true;
            while (!X.empty()) {
                int x = X.front(), y = Y.front();
                X.pop(), Y.pop();
                for (int k = 0; k < 8; ++k) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx < 0 || nx >= n) {
                        continue;
                    }
                    if (ny < 0 || ny >= m) {
                        continue;
                    }
                    if (visited[nx][ny] || a[nx][ny] != '*') {
                        continue;
                    }
                    X.push(nx), Y.push(ny);
                    visited[nx][ny] = true;
                    sz++;
                }
            }
            if (sz != 3) {
                return sz;
            }
            sz = 1;
            set<int> rows, cols;
            rows.insert(i), cols.insert(j);
            for (int k = 0; k < 8; ++k) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || nx >= n) {
                    continue;
                }
                if (ny < 0 || ny >= m) {
                    continue;
                }
                if (a[nx][ny] != '*') {
                    continue;
                }
                rows.insert(nx), cols.insert(ny);
                sz++;
            }
            return (sz == 3 && rows.size() == 2 && cols.size() == 2 ? 3 : 0);
        };
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!visited[i][j] && a[i][j] == '*') {
                    ok &= bfs(i, j) == 3;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
