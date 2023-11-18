/**
 *    author:  MaGnsi0
 *    created: 21.10.2023 20:04:15
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 3e3 + 5;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int n, m;
vector<string> a(N);
vector<vector<int>> add(N, vector<int>(N, 0));
vector<vector<bool>> visited(N, vector<bool>(N, false));

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("A2.in", "r", stdin);
    freopen("A2.out", "w", stdout);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                add[i][j] = visited[i][j] = 0;
            }
        }
        for (int x_ = 0; x_ < n; ++x_) {
            for (int y_ = 0; y_ < m; ++y_) {
                if (a[x_][y_] != 'W') { continue; }
                if (visited[x_][y_]) { continue; }
                int comp_size = 0;
                pair<int, int> good_add = make_pair(-1, -1);
                queue<int> X, Y;
                visited[x_][y_] = true;
                X.push(x_), Y.push(y_);
                while (!X.empty()) {
                    int x = X.front(); X.pop(); 
                    int y = Y.front(); Y.pop();
                    comp_size++;
                    for (int i = 0; i < 4; ++i) {
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if (nx < 0 || nx >= n) { continue; }
                        if (ny < 0 || ny >= m) { continue; }
                        if (a[nx][ny] == 'B') { continue; }
                        if (visited[nx][ny]) { continue; }
                        if (a[nx][ny] == '.') {
                            if (good_add == make_pair(nx, ny)) { continue; }
                            if (good_add == make_pair(-2, -2)) { continue; }
                            if (good_add == make_pair(-1, -1)) {
                                good_add = make_pair(nx, ny);
                            } else {
                                good_add = make_pair(-2, -2);
                            }
                            continue;
                        }
                        visited[nx][ny] = true;
                        X.push(nx), Y.push(ny);
                    }
                }
                if (good_add.first >= 0) {
                    add[good_add.first][good_add.second] += comp_size;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans = max(ans, add[i][j]);
            }
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
}
