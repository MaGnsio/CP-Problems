/**
 *    author:  MaGnsi0
 *    created: 23.12.2023 14:41:33
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int64_t power(int64_t b, int64_t p) {
    int64_t res = 1;
    while (p) {
        if (p & 1) { res = res * b % MOD; }
        b = b * b % MOD;
        p /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> b(n, vector<int>(m, -1));
    int greens = 0, reds = 0;
    function<void(int, int)> dfs = [&](int x, int y) {
        b[x][y] = greens;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n) { continue; }
            if (ny < 0 || ny >= m) { continue; }
            if (a[nx][ny] == '.') { continue; }
            if (b[nx][ny] != -1) { continue; }
            dfs(nx, ny);
        }
    };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            reds += a[i][j] == '.';
            if (a[i][j] == '#' && b[i][j] == -1) {
                dfs(i, j);
                greens++;
            }
        }
    }
    if (reds == 0) {
        cout << 1;
        return 0;
    }
    int64_t ans = 0, p = power(reds, MOD - 2);
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if (a[x][y] == '#') { continue; }
            set<int> connections;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n) { continue; }
                if (ny < 0 || ny >= m) { continue; }
                if (a[nx][ny] == '.') { continue; }
                connections.insert(b[nx][ny]);
            }
            int c = (int)connections.size();
            int new_greens = greens - (c == 0 ? -1 : (c == 1 ? 0 : c - 1));
            ans += p * new_greens % MOD;
            ans %= MOD;
        }
    }
    cout << ans;
}
