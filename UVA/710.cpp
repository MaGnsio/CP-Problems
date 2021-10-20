/**
 *    author:  MaGnsi0
 *    created: 21/06/2021 17:38:16
**/
#include <bits/stdc++.h>
using namespace std;

int bfs(int n, int m, vector<vector<char>> g, int x1, int y1, int x2, int y2) {
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    int dd[4] = {1, 2, 3, 4};
    vector<vector<int>> d(n, vector<int>(m, -1));
    deque<pair<int, pair<int, int>>> q;
    d[x1][y1] = 1;
    q.push_front({-1, {x1, y1}});
    while (!q.empty()) {
        int di = q.front().first, r = q.front().second.first, c = q.front().second.second;
        q.pop_front();
        for (int i = 0; i < 4; ++i) {
            int nr = r + dx[i], nc = c + dy[i];
            if (nr < 0 || nr >= n) {
                continue;
            }
            if (nc < 0 || nc >= m) {
                continue;
            }
            int k = d[r][c] + (di != -1 && di != dd[i]);
            if (d[nr][nc] == -1 || d[nr][nc] > k) {
                d[nr][nc] = k;
                if (g[nr][nc] != 'X') {
                    if (di != dd[i]) {
                        q.push_back({dd[i], {nr, nc}});
                    } else {
                        q.push_front({dd[i], {nr, nc}});
                    }
                }
            }
        }
    }
    return d[x2][y2];
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int W, H, T = 0;
    while ((cin >> W >> H) && (W && H)) {
        vector<vector<char>> g(H + 2, vector<char>(W + 2, '.'));
        cin.ignore();
        for (int i = 1; i <= H; ++i) {
            string s;
            getline(cin, s);
            for (int j = 0; j < W; ++j) {
                    g[i][j + 1] = (s[j] == 'X' ? 'X' : '.');
            }
        }
        int x1, y1, x2, y2, t = 0;
        cout<< "Board #" << ++T << ":\n";
        while ((cin >> y1 >> x1 >> y2 >> x2) && (x1 || y1 || x2 || y2)) {
            int res = bfs(H + 2, W + 2, g, x1, y1, x2, y2);
            cout << "Pair " << ++t << ": ";
            if (res == -1) {
                cout << "impossible.\n";
            } else {
                cout << res << " segments.\n";
            }
        }
        cout << "\n";
    }
}
