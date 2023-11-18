/**
 *    author:  MaGnsi0
 *    created: 27.09.2023 18:36:24
**/
#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

const int dx_f[8] = {0, 1, 2, 3, 4, 0, 0, 2};
const int dy_f[8] = {0, 0, 0, 0, 0, 1, 2, 1};

const int dx_q[10] = {0, 0, 0, 1, 2, 3, 4, 1, 2, 2};
const int dy_q[10] = {0, 1, 2, 2, 2, 2, 2, 0, 0, 1};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    function<bool(int, int)> countQ = [&](int x, int y) {
        for (int i = 0; i < 10; ++i) {
            int nx = x + dx_q[i];
            int ny = y + dy_q[i];
            if (nx < 0 || nx >= n) { return false; }
            if (ny < 0 || ny >= m) { return false; }
            if (a[nx][ny] == '.') { return false; }
        }
        for (int i = 0; i < 10; ++i) {
            int nx = x + dx_q[i];
            int ny = y + dy_q[i];
            a[nx][ny] = '.';
        }
        return true;
    };
    function<bool(int, int)> countF = [&](int x, int y) {
        for (int i = 0; i < 8; ++i) {
            int nx = x + dx_f[i];
            int ny = y + dy_f[i];
            if (nx < 0 || nx >= n) { return false; }
            if (ny < 0 || ny >= m) { return false; }
            if (a[nx][ny] == '.') { return false; }
        }
        for (int i = 0; i < 8; ++i) {
            int nx = x + dx_f[i];
            int ny = y + dy_f[i];
            a[nx][ny] = '.';
        }
        return true;
    };
    function<void(int, int, int, int)> solve = [&](int Q, int F, int i, int j) {
        int nj = (j + 1 < m ? j + 1 : 0);
        int ni = (j + 1 < m ? i : i + 1);
        if (ni == n) {
            cout << Q << " " << F;
            exit(0);
        }
        if (a[i][j] == '.') {
            solve(Q, F, ni, nj);
            return;
        }
        if (countF(i, j)) {
            solve(Q, F + 1, ni, nj);
            for (int k = 0; k < 8; ++k) {
                int nx = i + dx_f[k];
                int ny = j + dy_f[k];
                a[nx][ny] = '#';
            }
        }
        if (countQ(i, j)) {
            solve(Q + 1, F, ni, nj);
            for (int k = 0; k < 10; ++k) {
                int nx = i + dx_q[k];
                int ny = j + dy_q[k];
                a[nx][ny] = '#';
            }
        }
    };
    solve(0, 0, 0, 0);
}
