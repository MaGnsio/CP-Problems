/**
 *    author:  MaGnsi0
 *    created: 19.02.2022 19:52:33
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(m, vector<vector<int>>(m / 2 + 1, vector<int>(k, -1))));
    function<int(int, int, int, int)> solve = [&](int r, int c, int taken, int mod) {
        if (r == n) {
            return (mod != 0) * (int)-1e7;
        }
        int& ans = dp[r][c][taken][mod];
        if (ans != -1) {
            return ans;
        }
        ans = 0;
        if (taken == m / 2) {
            ans = solve(r + 1, 0, 0, mod);
        } else {
            if (c + 1 < m) {
                ans = max(a[r][c] + solve(r, c + 1, taken + 1, (mod + a[r][c]) % k), solve(r, c + 1, taken, mod));
            } else {
                ans = max(a[r][c] + solve(r + 1, 0, 0, (mod + a[r][c]) % k), solve(r + 1, 0, 0, mod));
            }
        }
        return ans;
    };
    cout << solve(0, 0, 0, 0);
}
