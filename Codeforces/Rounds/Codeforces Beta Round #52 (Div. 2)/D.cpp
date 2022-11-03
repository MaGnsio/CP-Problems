/**
 *    author:  MaGnsi0
 *    created: 11.09.2022 15:21:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s, t;
    cin >> s >> t;
    int n = (int)s.size();
    int m = (int)t.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    function<int(int, int)> solve = [&](int x, int y) {
        if (y == m) {
            return n - x; //delete
        }
        if (x == n) {
            return m - y; //insert
        }
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        if (s[x] == t[y]) {
            return dp[x][y] = solve(x + 1, y + 1);
        }
        dp[x][y] = min({solve(x + 1, y + 1), solve(x + 1, y), solve(x, y + 1)}) + 1; //(replace, delete, insert)
        return dp[x][y];
    };
    function<void(int, int)> build = [&](int x, int y) {
        if (y == m) {
            for (int i = x; i < n; ++i) {
                cout << "DELETE " << m + 1 << "\n";
            }
            return;
        }
        if (x == n) {
            for (int j = y; j < m; ++j) {
                cout << "INSERT " << j + 1 << " " << t[j] << "\n";
            }
            return;
        }
        if (s[x] == t[y]) {
            build(x + 1, y + 1);
            return;
        }
        int ans1 = solve(x + 1, y + 1); //replace
        int ans2 = solve(x + 1, y); //delete
        int ans3 = solve(x, y + 1); //insert
        int ans = min({solve(x + 1, y + 1), solve(x + 1, y), solve(x, y + 1)});
        if (ans1 == ans) {
            cout << "REPLACE " << y + 1 << " " << t[y] << "\n";
            build(x + 1, y + 1);
        } else if (ans2 == ans) {
            cout << "DELETE " << y + 1 << "\n";
            build(x + 1, y);
        } else {
            cout << "INSERT " << y + 1 << " " << t[y] << "\n";
            build(x, y + 1);
        }
        return;
    };
    cout << solve(0, 0) << "\n";
    build(0, 0);
}
