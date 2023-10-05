/**
 *    author:  MaGnsi0
 *    created: 30.05.2022 00:59:40
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> s(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            s[i][j] = a[i][j] == '1';
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            s[i][j] += s[i - 1][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            s[i][j] += s[i][j - 1];
        }
    }
    vector<vector<vector<vector<int64_t>>>> dp(n, vector<vector<vector<int64_t>>>(m, vector<vector<int64_t>>(n, vector<int64_t>(m, -1))));
    function<int64_t(int, int, int, int)> solve = [&](int x1, int y1, int x2, int y2) {
        if (x1 > x2 || y1 > y2) {
            return int64_t(0);
        }
        if (x1 == x2 && y1 == y2) {
            return int64_t(a[x1][y1] == '0');
        }
        int64_t& ans = dp[x1][y1][x2][y2];
        if (ans != -1) {
            return ans;
        }
        ans = (s[x2][y2] - (x1 ? s[x1 - 1][y2] : 0) - (y1 ? s[x2][y1 - 1] : 0) + (x1 && y1 ? s[x1 - 1][y1 - 1] : 0) == 0);
        ans += solve(x1 + 1, y1, x2, y2);
        ans += solve(x1, y1 + 1, x2, y2);
        ans += solve(x1, y1, x2 - 1, y2);
        ans += solve(x1, y1, x2, y2 - 1);
        ans -= solve(x1 + 1, y1 + 1, x2, y2);
        ans -= solve(x1 + 1, y1, x2 - 1, y2);
        ans -= solve(x1 + 1, y1, x2, y2 - 1);
        ans -= solve(x1, y1 + 1, x2 - 1, y2);
        ans -= solve(x1, y1 + 1, x2, y2 - 1);
        ans -= solve(x1, y1, x2 - 1, y2 - 1);
        ans += solve(x1 + 1, y1 + 1, x2 - 1, y2);
        ans += solve(x1 + 1, y1 + 1, x2, y2 - 1);
        ans += solve(x1 + 1, y1, x2 - 1, y2 - 1);
        ans += solve(x1, y1 + 1, x2 - 1, y2 - 1);
        ans -= solve(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
        return ans;
    };
    for (int i = 0; i < q; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << solve(x1 - 1, y1 - 1, x2 - 1, y2 - 1) << "\n";
    }
}
