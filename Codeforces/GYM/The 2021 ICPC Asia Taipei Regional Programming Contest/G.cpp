/**
 *    author:  MaGnsi0
 *    created: 18.07.2022 21:32:44
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e6;
const int dx[5] = {-1, 0, 0, 0, 1};
const int dy[5] = {0, -1, 0, 1, 0};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        int sx, sy;
        cin >> sy >> sx;
        int g, lcm = 1;
        cin >> g;
        vector<int> b(g);
        vector<vector<pair<int, int>>> c(g);
        for (int i = 0; i < g; ++i) {
            cin >> b[i];
            c[i].resize(b[i]);
            for (int j = 0; j < b[i]; ++j) {
                cin >> c[i][j].second >> c[i][j].first;
            }
            lcm = lcm * b[i] / __gcd(lcm, b[i]);
        }
        int ans = -1;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(lcm, OO)));
        queue<tuple<int, int, int>> q;
        q.emplace(sx, sy, 0);
        dp[sx][sy][0] = 0;
        while (!q.empty()) {
            int x = get<0>(q.front());
            int y = get<1>(q.front());
            int t = get<2>(q.front());
            q.pop();
            if (a[x][y] == 0) {
                ans = dp[x][y][t];
                break;
            }
            for (int i = 0; i < 5; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nt = (t + 1) % lcm;
                if (nx < 0 || nx >= m) {
                    continue;
                }
                if (ny < 0 || ny >= n) {
                    continue;
                }
                if (dp[x][y][t] + 1 >= dp[nx][ny][nt]) {
                    continue;
                }
                if (a[nx][ny] > a[x][y]) {
                    continue;
                }
                bool have_guard = false;
                for (int j = 0; j < g; ++j) {
                    have_guard |= c[j][nt % b[j]] == make_pair(nx, ny);
                    have_guard |= c[j][(nt - 1 + b[j]) % b[j]] == make_pair(nx, ny);
                }
                if (have_guard) {
                    continue;
                }
                dp[nx][ny][nt] = dp[x][y][t] + 1;
                q.emplace(nx, ny, nt);
            }
        }
        cout << ans << "\n";
    }
}
