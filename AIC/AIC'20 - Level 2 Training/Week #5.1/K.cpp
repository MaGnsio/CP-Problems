//https://vjudge.net/contest/434102#problem/K
#include <bits/stdc++.h>
using namespace std;

bool valid (int r, int c, int n) {
    if (r < n && r >= 0 && c < n && c >= 0) {
        return true;
    }
    return false;
}

void solve (int s, int x, int y, int r, int c, int n, vector<vector<int>> &v, vector<vector<int>> &a) {
    a[r][c] = v[x][y];
    if (r == n - 1 && c == n - 1) {
        return;
    }
    int ns, nx, ny;
    int nr = (c == n - 1 ? r + 1 : r);
    int nc = (c == n - 1 ? 0 : c + 1);
    if (s == 0) {
        if (valid (x, y + 1, n)) {
            nx = x;
            ny = y + 1;
            ns = s + 1;
        } else if (valid (x + 1, y, n)) {
            nx = x + 1;
            ny = y;
            ns = s + 1;
        }
    } else if (s % 3 == 1) {
        if (valid (x + 1, y - 1, n)) {
            nx = x + 1;
            ny = y - 1;
            ns = s;
        } else if (valid (x + 1, y, n)) {
            nx = x + 1;
            ny = y;
            ns = s + 1;
        } else if (valid (x, y + 1, n)) {
            nx = x;
            ny = y + 1;
            ns = s + 1;
        }
    } else if (s % 3 == 2) {
        if (valid (x - 1, y + 1, n)) {
            nx = x - 1;
            ny = y + 1;
            ns = s;
        } else if (valid (x, y + 1, n)) {
            nx = x;
            ny = y + 1;
            ns = s + 2;
        } else if (valid (x + 1, y, n)) {
            nx = x + 1;
            ny = y;
            ns = s + 2;
        }
    }
    solve (ns, nx, ny, nr, nc, n, v, a);
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
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
}

