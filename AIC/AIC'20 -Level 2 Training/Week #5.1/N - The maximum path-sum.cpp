//https://vjudge.net/contest/434102#problem/N
#include <bits/stdc++.h>
using namespace std;

int solve (int n, int m, vector<vector<int>> &v, int x = 0, int y = 0) {
    if (x == n - 1 && y == m - 1) {
        return v[x][y];
    }
    if (x + 1 < n && y + 1 < m) {
        return max (v[x][y] + solve (n, m, v, x + 1, y), v[x][y] + solve (n, m, v, x, y + 1));
    } else if (x + 1 < n) {
        return v[x][y] + solve (n, m, v, x + 1, y);
    } else {
        return v[x][y] + solve (n, m, v, x, y + 1);
    }
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int> (m));
    for (auto& x : v) {
        for (auto& y : x) {
            cin >> y;
        }
    }
    int ans = solve (n, m, v);
    cout << ans;
}

