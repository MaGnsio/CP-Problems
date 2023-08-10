/**
 *    author:  MaGnsi0
 *    created: 30.03.2023 23:02:04
**/
#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    set<tuple<int, int, int, int>> s;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j]) {
                s.emplace(0, a[i][j], i, j);
            }
        }
    }
    while (!s.empty()) {
        int d = get<0>(*s.begin()), c = get<1>(*s.begin());
        int x = get<2>(*s.begin()), y = get<3>(*s.begin());
        s.erase(s.begin());
        if (d >= k) { continue; }
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n) { continue; }
            if (ny < 0 || ny >= m) { continue; }
            if (a[nx][ny]) { continue; }
            a[nx][ny] = c;
            s.emplace(d + 1, a[nx][ny], nx, ny);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}
