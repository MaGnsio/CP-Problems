/**
 *    author:  MaGnsi0
 *    created: 27.07.2023 18:17:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(2, -1))));
    function<int(int, int, int, int)> solve = [&](int j, int x, int y, int z) {
        if (j == n) { return z; }
        int& ans = dp[j][x][y][z];
        if (ans != -1) { return ans; }
        ans = n + 1;
        if (y) {
            if (x) {
                ans = min(ans, solve(j + 1, int(!!a[j + 1]), 1, z));
            }
            ans = min(ans, solve(j + 1, int(!!a[j + 1]), 0, 0) + z);
        } else {
            if (x) {
                ans = min(ans, solve(j + 1, int(!!a[j + 1]), 1, 1));
            }
            if (a[j + 1]) {
                ans = min(ans, solve(j + 1, int(a[j + 1] == 2), 0, 1));
            }
            ans = min(ans, solve(j + 1, int(!!a[j + 1]), 0, 0) + 1);
        }
        return ans;
    };
    cout << solve(0, !!a[0], 0, 0);
}
