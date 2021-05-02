//https://vjudge.net/contest/434102#problem/J
#include <bits/stdc++.h>
using namespace std;

void solve (int s, int x, int y, int r, int c, int n, vector<vector<int>> &v, vector<vector<int>> &a) {
    a[r][c] = v[x][y];
    v[x][y] = INT_MAX;
    if (r == n - 1 && c == n - 1) {
        return;
    }
    int nx, ny, ns;
    int nr = (c == n - 1 ? r + 1 : r);
    int nc = (c == n - 1 ? 0 : c + 1);
    if (s % 4 == 0) {
        if (y != n - 1 && v[x][y + 1] != INT_MAX) {
            nx = x;
            ny = y + 1;
            ns = s;
        } else {
            nx = x + 1;
            ny = y;
            ns = s + 1;
        }
    } else if (s % 4 == 1) {
        if (x != n - 1 && v[x + 1][y] != INT_MAX) {
            nx = x + 1;
            ny = y;
            ns = s;
        } else {
            nx = x;
            ny = y - 1;
            ns = s + 1;
        }
    } else if (s % 4 == 2) {
        if (y != 0 && v[x][y - 1] != INT_MAX) {
            nx = x;
            ny = y - 1;
            ns = s;
        } else {
            nx = x - 1;
            ny = y;
            ns = s + 1;
        }
    } else if (s % 4 == 3) {
        if (x != 0 && v[x - 1][y] != INT_MAX) {
            nx = x - 1;
            ny = y;
            ns = s;
        } else {
            nx = x;
            ny = y + 1;
            ns = s + 1;
        }
    }
    solve (ns, nx, ny, nr, nc, n, v, a);
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<vector<int>> v (n, vector<int> (n)), a (n, vector<int> (n));
    for (auto& x : v) {
        for (auto& y : x) {
            cin >> y;
        }
    }
    solve (0, 0, 0, 0, 0, n, v, a);
    for (auto& x : a) {
        for (auto& y : x) {
            cout << y << " ";
        }
        cout << "\n";
    }
}

