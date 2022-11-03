/**
 *    author:  MaGnsi0
 *    created: 20.10.2022 06:40:00
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e7;
const int dx1[4] = {-1, 0, 0, 1};
const int dy1[4] = {0, -1, 1, 0};
const int dx2[4] = {-1, -1, 1, 1};
const int dy2[4] = {-1, 1, -1, 1};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        function<bool(int, int)> empty = [&](int x, int y) {
            if (x < 0 || x >= n) { return true; }
            if (y < 0 || y >= m) { return true; }
            if (a[x][y] == '.') { return true; }
            return false;
        };
        function<bool(int, int)> all_empty = [&](int x, int y) {
            bool yup = true;
            for (int i = 0; i < 4; ++i) {
                yup &= empty(x + dx1[i], y + dy1[i]);
            }
            return yup;
        };
        vector<vector<int>> d(n, vector<int>(m, OO));
        vector<vector<pair<int, int>>> p(n, vector<pair<int, int>>(m, {-1, -1}));
        vector<vector<bool>> done(n, vector<bool>(m, false));
        set<tuple<int, int, int>> s;
        for (int i = 0; i < n; ++i) {
            if (all_empty(i, 0)) {
                d[i][0] = (a[i][0] == '.');
                done[i][0] = true;
                s.emplace(d[i][0], i, 0);
            }
        }
        while (!s.empty()) {
            int x = get<1>(*s.begin());
            int y = get<2>(*s.begin());
            s.erase(s.begin());
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx2[i];
                int ny = y + dy2[i];
                if (nx < 0 || nx >= n) {
                    continue;
                }
                if (ny < 0 || ny >= m) {
                    continue;
                }
                if (!all_empty(nx, ny)) {
                    continue;
                }
                if (d[nx][ny] > d[x][y] + (a[nx][ny] == '.')) {
                    d[nx][ny] = d[x][y] + (a[nx][ny] == '.');
                    p[nx][ny] = make_pair(x, y);
                    done[nx][ny] = true;
                    s.emplace(d[nx][ny], nx, ny);
                }
            }
        }
        int ans = OO;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, d[i][m - 1]);
        }
        if (ans == OO) {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i < n; ++i) {
            if (d[i][m - 1] == ans) {
                pair<int, int> P = make_pair(i, m - 1);
                while (P != make_pair(-1, -1)) {
                    a[P.first][P.second] = '#';
                    P = p[P.first][P.second];
                }
                break;
            }
        }
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            cout << a[i] << "\n";
        }
    }
}
