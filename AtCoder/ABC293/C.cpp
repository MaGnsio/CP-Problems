/**
 *    author:  MaGnsi0
 *    created: 13.03.2023 23:30:40
**/
#include <bits/stdc++.h>

using namespace std;

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
    set<int> cur_path;
    function<int(int, int)> solve = [&](int x, int y) {
        if (x == n - 1 && y == m - 1) {
            return 1;
        }
        int ans = 0;
        if (x + 1 < n && cur_path.count(a[x + 1][y]) == 0) {
            cur_path.insert(a[x + 1][y]);
            ans += solve(x + 1, y);
            cur_path.erase(a[x + 1][y]);
        }
        if (y + 1 < m && cur_path.count(a[x][y + 1]) == 0) {
            cur_path.insert(a[x][y + 1]);
            ans += solve(x, y + 1);
            cur_path.erase(a[x][y + 1]);
        }
        return ans;
    };
    cur_path.insert(a[0][0]);
    cout << solve(0, 0);
}
