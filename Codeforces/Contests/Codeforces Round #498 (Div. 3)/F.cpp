/**
 *    author:  MaGnsi0
 *    created: 07.12.2023 13:25:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    int64_t k; cin >> k;
    vector<vector<int64_t>> a(n, vector<int64_t>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    int64_t ans = 0;
    int forward_limit = (n + m - 2) / 2;
    int backward_limit = n + m - 2 - forward_limit;
    vector<vector<map<int64_t, int64_t>>> b(n, vector<map<int64_t, int64_t>>(m));
    function<void(int, int, int64_t)> forward = [&](int x, int y, int64_t _xor) {
        if (x + y == forward_limit) {
            b[x][y][_xor ^ a[x][y]]++;
            return;
        }
        if (x + 1 < n) {
            forward(x + 1, y, _xor ^ a[x][y]);
        }
        if (y + 1 < m) {
            forward(x, y + 1, _xor ^ a[x][y]);
        }
    };
    function<void(int, int, int64_t)> backward = [&](int x, int y, int64_t _xor) {
        if ((n - 1) - x + (m - 1) - y == backward_limit) {
            if (b[x][y].count(_xor ^ k)) {
                ans += b[x][y][_xor ^ k];
            }
            return;
        }
        if (x) {
            backward(x - 1, y, _xor ^ a[x][y]);
        }
        if (y) {
            backward(x, y - 1, _xor ^ a[x][y]);
        }
    };
    forward(0, 0, 0);
    backward(n - 1, m - 1, 0);
    cout << ans;
}
