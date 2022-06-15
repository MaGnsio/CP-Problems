/**
 *    author:  MaGnsi0
 *    created: 30.03.2022 20:49:03
**/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    vector<tuple<int, int, int>> b;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            b.push_back(make_tuple(a[i][j], i, j));
        }
    }
    sort(b.begin(), b.end());
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(4, -1)));
    function<int(int, int, int)> solve = [&](int x, int y, int z) {
        int& ans = dp[x][y][z];
        if (ans != -1) {
            return ans;
        }
        ans = 0;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n) {
                continue;
            }
            if (ny < 0 || ny >= m) {
                continue;
            }
            if (a[nx][ny] != a[x][y] + 1) {
                continue;
            }
            ans = (ans + solve(nx, ny, max(z - 1, 0))) % MOD;
        }
        if (!ans) {
            return ans = (z ? 0 : 1);
        }
        return ans;
    };
    int res = 0;
    for (int i = 0; i < n * m; ++i) {
        bool ok = false;
        for (int j = 0; j < 4; ++j) {
            ok = (ok || (dp[get<1>(b[i])][get<2>(b[i])][j] != -1));
        }
        if (!ok) {
            res = (res + solve(get<1>(b[i]), get<2>(b[i]), 3)) % MOD;
        }
    }
    cout << res;
}
