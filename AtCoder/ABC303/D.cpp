/**
 *    author:  MaGnsi0
 *    created: 27.05.2023 15:18:58
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e16;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t x, y, z;
    cin >> x >> y >> z;
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<vector<int64_t>> dp(n, vector<int64_t>(2, -1));
    function<int64_t(int, int)> solve = [&](int j, int light) {
        if (j == n) { return int64_t(0); }
        if (dp[j][light] != -1) { return dp[j][light]; }
        dp[j][light] = OO;
        if (s[j] == 'A') {
            if (light) {
                dp[j][light] = solve(j + 1, 1) + x;
                dp[j][light] = min(dp[j][light], solve(j + 1, 0) + z + y);
            } else {
                dp[j][light] = solve(j + 1, 0) + y;
                dp[j][light] = min(dp[j][light], solve(j + 1, 1) + z + x);
            }
        } else {
            if (light) {
                dp[j][light] = solve(j + 1, 1) + y;
                dp[j][light] = min(dp[j][light], solve(j + 1, 0) + z + x);
            } else {
                dp[j][light] = solve(j + 1, 0) + x;
                dp[j][light] = min(dp[j][light], solve(j + 1, 1) + z + y);
            }
        }
        return dp[j][light];
    };
    int64_t ans = solve(0, 0);
    cout << ans;
}
