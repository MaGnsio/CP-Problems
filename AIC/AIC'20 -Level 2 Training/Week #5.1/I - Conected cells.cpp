//https://vjudge.net/contest/434102#problem/I
#include <bits/stdc++.h>
using namespace std;

int solve (char c, int i, int j, vector<vector<char>> &v, int n, int m) {
    if (i < 0 || i >= n || j < 0 || j >= m || v[i][j] != c) {
        return 0;
    }
    v[i][j] = '0';
    return (1 + solve (c, i + 1, j, v, n, m) + solve (c, i - 1, j, v, n, m) + solve (c, i, j + 1, v, n, m) + solve (c, i, j - 1, v, n, m));
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, cnt = 0;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char> (m));
    for (auto& x : v) {
        for (auto& y : x) {
            cin >> y;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[i][j] == '0') {
                continue;
            }
            if (solve (v[i][j], i, j, v, n, m)) {
                cnt++;
            }
        }
    }
    cout << cnt;
}

