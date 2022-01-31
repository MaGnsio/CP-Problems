/**
 *    author:  MaGnsi0
 *    created: 26.12.2021 21:11:40
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, t, w;
    cin >> n >> m >> t >> w;
    swap(n, m);
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (a[0][0] == '#') {
        cout << "IMPOSSIBLE";
        return 0;
    }
    vector<vector<int>> d(n, vector<int>(m, -1));
    queue<int> x, y;
    {
        d[0][0] = 0LL;
        x.push(0), y.push(0);
        while (!x.empty()) {
            int r = x.front(), c = y.front();
            x.pop(), y.pop();
            int dx[4] = {-1, 0, 0, 1};
            int dy[4] = {0, -1, 1, 0};
            for (int i = 0; i < 4; ++i) {
                int nr = r + dx[i];
                int nc = c + dy[i];
                if (nr < 0 || nr >= n) {
                    continue;
                }
                if (nc < 0 || nc >= m) {
                    continue;
                }
                if (a[nr][nc] == '#' || d[nr][nc] != -1) {
                    continue;
                }
                d[nr][nc] = d[r][c] + 1;
                x.push(nr), y.push(nc);
            }
        }
    }
    if (d[n - 1][m - 1] == -1) {
        cout << "IMPOSSIBLE";
    } else {
        int x = d[n - 1][m - 1] / 2;
        cout << x * t + x * w + (d[n - 1][m - 1] & 1) * w;
    }
}
