/**
 *    author:  MaGnsi0
 *    created: 10.11.2024 16:47:04
**/
#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = 0;
        vector<vector<bool>> done(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (done[i][j]) { continue; }
                string s = ""; s += a[i][j];
                int x = i, y = j, k = 0;
                done[i][j] = true;
                while (true) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx < 0 || nx >= n) { k = (k + 1) % 4; continue; }
                    if (ny < 0 || ny >= m) { k = (k + 1) % 4; continue; }
                    if (nx == i && ny == j) { break; }
                    if (done[nx][ny]) { k = (k + 1) % 4; continue; }
                    x = nx; y = ny; done[x][y] = true; s += a[x][y];
                }
                int sz = (int)s.size();
                for (int x = 0; x + 3 < sz; ++x) {
                    ans += s.substr(x, 4) == "1543";
                }
                ans += s.substr(sz - 1, 1) == "1" && s.substr(0, 3) == "543";
                ans += s.substr(sz - 2, 2) == "15" && s.substr(0, 2) == "43";
                ans += s.substr(sz - 3, 3) == "154" && s.substr(0, 1) == "3";
            }
        }
        cout << ans << "\n";
    }
}
