//https://vjudge.net/contest/434102#problem/G
#include <bits/stdc++.h>
using namespace std;

int solve (int x, int y, vector<vector<char>> &v, int n, int m) {
    if (x < 0 || x >= n || y < 0 || y >= m || v[x][y] != '.') {
        return 0;
    }
    v[x][y] = '1';
    return (1 + solve (x - 1, y, v, n, m) + solve (x + 1, y, v, n, m) + solve (x, y - 1, v, n, m) + solve (x, y + 1, v, n, m));
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, x, y;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char> (m));
    for (auto& r : v) {
        for (auto& c : r) {
            cin >> c;
        }
    }
    cin >> x >> y;
    int ans = solve (x - 1, y - 1, v, n, m);
    cout << ans;
}
