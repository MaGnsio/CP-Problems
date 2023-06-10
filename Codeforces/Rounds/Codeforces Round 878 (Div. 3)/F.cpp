/**
 *    author:  MaGnsi0
 *    created: 06.06.2023 20:03:01
**/
#include <bits/stdc++.h>

using namespace std;

const int dx[2] = {0, 1};
const int dy[2] = {1, 0};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<set<pair<int, int>>> a(2);
        for (int i = 0; i < k; ++i) {
            int t, j, x;
            cin >> t >> j >> x;
            a[j - 1].emplace(t, x);
        }
        vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(m + 1, vector<bool>(k + 1, false)));
        queue<tuple<int, int, int>> q;
        dp[0][0][0] = true;
        q.emplace(0, 0, 0);
        while (!q.empty()) {
            int x = get<0>(q.front());
            int y = get<1>(q.front());
            int w = get<2>(q.front());
            int t = x + y + w;
            q.pop();
            for (int j = 0; j < 2; ++j) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                int nw = (a[0].count(make_pair(t + 1, nx)) || a[1].count(make_pair(t + 1, ny)));
                if (nw) { continue; }
                if (nx > n) { continue; }
                if (ny > m) { continue; }
                if (dp[nx][ny][w] == true) { continue; }
                dp[nx][ny][w] = true;
                q.emplace(nx, ny, w);
            }
            if (a[0].count(make_pair(t + 1, x)) == 0 && a[1].count(make_pair(t + 1, y)) == 0 && w + 1 <= k) {
                dp[x][y][w + 1] = true;
                q.emplace(x, y, w + 1);
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i <= k; ++i) {
            if (dp[n][m][i]) {
                ans = min(ans, n + m + i);
            }
        }
        cout << (ans == INT_MAX ? -1 : ans) << "\n";
    }
}
