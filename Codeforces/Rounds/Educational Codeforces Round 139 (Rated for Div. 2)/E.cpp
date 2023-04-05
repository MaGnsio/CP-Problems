/**
 *    author:  MaGnsi0
 *    created: 14.12.2022 13:40:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<vector<vector<int64_t>>>> dp(n, vector<vector<vector<int64_t>>>(4, vector<vector<int64_t>>(4, vector<int64_t>(4, -1))));
    function<int64_t(int, int, int, int)> solve = [&](int j, int x, int y, int z) {
        if (j == n) {
            return int64_t(0);
        }
        int64_t& ans = dp[j][x][y][z];
        if (ans != -1) {
            return ans;
        }
        if (a[j] == 0) {
            ans = (n - j) + (x > 0) + (y > 0) + (z > 0) + solve(j + 1, x, y, z);
        } else if ((x == 0) || (x & a[j])) {
            ans = (y > 0) + (z > 0) + solve(j + 1, a[j], y, z) + 1;
        } else if ((y == 0) || (y & a[j])) {
            ans = (x > 0) + (z > 0) + solve(j + 1, x, a[j], z) + 1;
        } else {
            ans = (x > 0) + (y > 0) + solve(j + 1, x, y, a[j]) + 1;
        }
        return ans;
    };
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += solve(i, 0, 0, 0);
    }
    cout << ans;
}
