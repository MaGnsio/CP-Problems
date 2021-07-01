/**
 *    author:  MaGnsi0
 *    created: 17/06/2021 20:21:49
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> g[i][j];
            }
        }
        int dx[4] = {-1, 0, 0, 1};
        int dy[4] = {0, -1, 1, 0};
        vector<vector<int>> d(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        d[0][0] = g[0][0];
        q.push({d[0][0], {0, 0}});
        while (!q.empty()) {
            int r = q.top().second.first, c = q.top().second.second, d_v = q.top().first;
            q.pop();
            if (d[r][c] != d_v) {
                continue;
            }
            for (int i = 0; i < 4; ++i) {
                int nr = r + dx[i], nc = c + dy[i];
                if (nr < 0 || nr >= n) {
                    continue;
                }
                if (nc < 0 || nc >= m) {
                    continue;
                }
                if (d[r][c] + g[nr][nc] < d[nr][nc]) {
                    d[nr][nc] = d[r][c] + g[nr][nc];
                    q.push({d[nr][nc], {nr, nc}});
                }
            }
        }
        cout << d[n - 1][m - 1] << "\n";
    }
}
