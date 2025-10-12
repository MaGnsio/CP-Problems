/**
 *    author:  MaGnsi0
 *    created: 12.10.2025 03:34:17
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e8;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        int n; cin >> n;
        int m; cin >> m;
        int l; cin >> l;
        vector<string> a(n + 2, string(m + 2, '#'));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> a[i][j];
            }
        }
        vector d(n + 2, vector<int>(m + 2, OO));
        {
            queue<int> X, Y;
            for (int x = 0; x < n + 2; ++x) {
                for (int y = 0; y < m + 2; ++y) {
                    if (a[x][y] == '#') {
                        X.push(x); Y.push(y); d[x][y] = 0;
                    }
                }
            }
            while (!X.empty()) {
                int x = X.front(); X.pop();
                int y = Y.front(); Y.pop();
                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 || nx >= n + 2) { continue; }
                    if (ny < 0 || ny >= m + 2) { continue; }
                    if (d[nx][ny] != OO) { continue; }
                    X.push(nx); Y.push(ny); d[nx][ny] = d[x][y] + 1;
                }
            }
        }
        for (int x = 0; x < n + 2; ++x) {
            for (int y = 0; y < m + 2; ++y) {
                if (d[x][y] <= l) { a[x][y] = '#'; }
            }
        }
        int ans = 0;
        {
            int c = 0;
            vector visited(n + 2, vector<bool>(m + 2, false));
            function<void(int, int)> dfs = [&](int x, int y) {
                visited[x][y] = true; c++;
                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 || nx >= n + 2) { continue; }
                    if (ny < 0 || ny >= m + 2) { continue; }
                    if (visited[nx][ny]) { continue; }
                    if (a[nx][ny] == '#') { continue; }
                    dfs(nx, ny);
                }
            };
            for (int x = 0; x < n + 2; ++x) {
                for (int y = 0; y < m + 2; ++y) {
                    if (!visited[x][y] && a[x][y] != '#') {
                        dfs(x, y); ans = max(ans, c); c = 0;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}
