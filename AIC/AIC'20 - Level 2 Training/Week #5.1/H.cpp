//https://vjudge.net/contest/434102#problem/H
#include <bits/stdc++.h>
using namespace std;

bool solve (int x, int y, vector<vector<char>> &v, int n, int m) {
    if (x < 0 || x >= n || y < 0 || y >= m || v[x][y] == '*') {
        return false;
    }
    if (v[x][y] == 'E') {
        return true;
    }
    v[x][y] = '*';
    return (solve (x - 1, y, v, n, m) || solve (x + 1, y, v, n, m) || solve (x, y - 1, v, n, m) || solve (x, y + 1, v, n, m));
    v[x][y] = '.';
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, x, y;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
            if (v[i][j] == 'S') {
                x = i, y = j;
            }
        }
    }
    cout << (solve (x, y, v, n, m) ? "YES" : "NO");
}
