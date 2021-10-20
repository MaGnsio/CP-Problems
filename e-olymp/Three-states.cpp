/**
 *    author:  MaGnsi0
 *    created: 10/06/2021 02:00:53
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }
    int d[3][n][m]; //d[x][i][j] -> shortest path from point g[i][j] to state x + 1
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    memset(d, -1, sizeof d);
    for (char s = '1'; s <= '3'; ++s) {
        /*
         *  get all the points in state s and do a multisource bfs on them
         *  to get shortest path from all the points to state s
         */
        deque<int> x, y;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (g[i][j] == s) {
                    x.push_back(i), y.push_back(j);
                    d[s - '1'][i][j] = 0;
                }
            }
        }
        while(!x.empty()) {
            int r = x.front(), c = y.front();
            x.pop_front(), y.pop_front();
            for (int j = 0; j < 4; ++j) {
                int nr = r + dx[j], nc = c + dy[j];
                if (nr < 0 || nr >= n) {
                    continue;
                }
                if (nc < 0 || nc >= m) {
                    continue;
                }
                if (g[nr][nc] == '#') {
                    continue;
                }
                int nd = d[s - '1'][r][c] + (g[nr][nc] == '.');
                if (d[s - '1'][nr][nc] == -1 || nd < d[s - '1'][nr][nc]) {
                    d[s - '1'][nr][nc] = nd;
                    /*
                     *  as getting to states is what we care about
                     *  we push front all the state points (0-1 bfs)
                     */
                    if (g[nr][nc] == '.') {
                        x.push_back(nr), y.push_back(nc);
                    } else {
                        x.push_front(nr), y.push_front(nc);
                    }
                }
            }
        }
    }
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (d[0][i][j] != -1 && d[1][i][j] != -1 && d[2][i][j] != -1) {
                int nd = d[0][i][j] + d[1][i][j] + d[2][i][j] - 2 * (g[i][j] == '.');
                if (ans == -1 || nd < ans) {
                    ans = nd;
                }
            }
        }
    }
    cout << ans;
}
