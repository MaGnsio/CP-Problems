/**
 *    author:  MaGnsi0
 *    created: 27.11.2024 20:08:31
**/
#include <bits/stdc++.h>

using namespace std;

const int K = 9, OO = 1e8;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int sx, sy, ex, ey;
    map<pair<int, int>, int> mpc;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'S') {
                sx = i, sy = j;
            }
            if (a[i][j] == 'E') {
                ex = i, ey = j;
            }
            if (a[i][j] == 'C') {
                mpc[{i, j}] = (int)mpc.size();
            }
        }
    }
    queue<tuple<int, int, int, int>> Q;
    vector dp(n, vector(m, vector(K, vector<int>(1 << K, -1))));
    Q.emplace(sx, sy, 0, 0); dp[sx][sy][0][0] = 0;
    while (!Q.empty()) {
        auto [x, y, c, mc] = Q.front(); Q.pop();
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n) { continue; }
            if (ny < 0 || ny >= m) { continue; }
            if (a[nx][ny] == 'P') { continue; }
            int nc = c + (a[nx][ny] == 'C' && !(mc >> mpc[{nx, ny}] & 1)) - (a[nx][ny] == 'J');
            if (nc < 0) { continue; }
            int nmc = mc | (a[nx][ny] == 'C' ? (1 << mpc[{nx, ny}]) : 0);
            if (dp[nx][ny][nc][nmc] != -1) { continue; }
            Q.emplace(nx, ny, nc, nmc);
            dp[nx][ny][nc][nmc] = dp[x][y][c][mc] + 1;
        }
    }
    int ans = OO;
    for (int c = 0; c < K; ++c) {
        for (int mc = 0; mc < (1 << K); ++mc) {
            if (dp[ex][ey][c][mc] != -1) {
                ans = min(ans, dp[ex][ey][c][mc]);
            }
        }
    }
    if (ans == OO) {
        cout << "SPOOKED!";
    } else {
        cout << ans;
    }
}
