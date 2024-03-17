/**
 *    author:  MaGnsi0
 *    created: 31.12.2023 15:39:15
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int dx[2] = {0, 1};
const int dy[2] = {1, 0};

int n, a[N][N], b[2][N][N], dp[2][N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 0) {
                a[i][j] = -1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == -1) {
                b[0][i][j] = b[1][i][j] = -1;
            }
            while (a[i][j] % 2 == 0) {
                b[0][i][j]++;
                a[i][j] /= 2;
            }
            while (a[i][j] % 5 == 0) {
                b[1][i][j]++;
                a[i][j] /= 5;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[0][i][j] = dp[1][i][j] = 1e9;
        }
    }
    dp[0][n - 1][n - 1] = b[0][n - 1][n - 1];
    dp[1][n - 1][n - 1] = b[1][n - 1][n - 1];
    for (int x = n - 1; x >= 0; --x) {
        for (int y = n - 1; y >= 0; --y) {
            for (int i = 0; i < 2; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n) { continue; }
                if (ny < 0 || ny >= n) { continue; }
                if (b[0][x][y] != -1 && b[0][nx][ny] != -1) {
                    dp[0][x][y] = min(dp[0][x][y], dp[0][nx][ny] + b[0][x][y]);
                }
                if (b[1][x][y] != -1 && b[1][nx][ny] != -1) {
                    dp[1][x][y] = min(dp[1][x][y], dp[1][nx][ny] + b[1][x][y]);
                }
            }
        }
    }
    pair<int, string> ans = {1e9, ""};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == -1) {
                string path = "";
                for (int x = 0; x < i; ++x) {
                    path += "D";
                }
                for (int y = 0; y < j; ++y) {
                    path += "R";
                }
                for (int x = 0; x < n - i - 1; ++x) {
                    path += "D";
                }
                for (int y = 0; y < n - j - 1; ++y) {
                    path += "R";
                }
                ans = make_pair(1, path);
                goto found_zero;
            }
        }
    }
    found_zero:
    string path[2] = {"", ""};
    for (int x = 0, y = 0; x != n - 1 || y != n - 1; /*_*/) {
        int nextx = -1, nexty = -1;
        for (int i = 0; i < 2; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n) { continue; }
            if (ny < 0 || ny >= n) { continue; }
            if (dp[0][x][y] == dp[0][nx][ny] + b[0][x][y]) {
                nextx = nx, nexty = ny;
            }
        }
        if (nextx == x) {
            path[0] += "R";
        } else {
            path[0] += "D";
        }
        x = nextx, y = nexty;
    }
    for (int x = 0, y = 0; x != n - 1 || y != n - 1; /*_*/) {
        int nextx = -1, nexty = -1;
        for (int i = 0; i < 2; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n) { continue; }
            if (ny < 0 || ny >= n) { continue; }
            if (dp[1][x][y] == dp[1][nx][ny] + b[1][x][y]) {
                nextx = nx, nexty = ny;
            }
        }
        if (nextx == x) {
            path[1] += "R";
        } else {
            path[1] += "D";
        }
        x = nextx, y = nexty;
    }
    if (dp[0][0][0] != -1) {
        ans = min(ans, make_pair(dp[0][0][0], path[0]));
    }
    if (dp[1][0][0] != -1) {
        ans = min(ans, make_pair(dp[1][0][0], path[1]));
    }
    cout << ans.first << "\n";
    cout << ans.second;
}
