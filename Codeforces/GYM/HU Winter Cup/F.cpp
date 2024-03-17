/**
 *    author:  MaGnsi0
 *    created: 22.02.2024 21:58:39
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int w; cin >> w;
    vector<vector<pair<int64_t, int64_t>>> dp(n + 1, vector<pair<int64_t, int64_t>>(w + 1, {-1, -1}));
    function<pair<int64_t, int64_t>(int, int)> solve = [&](int x, int y) {
        if (y == 0) { return make_pair(0LL, 1LL); }
        if (y < 0 || x == n + 1) { return make_pair(0LL, 0LL); }
        if (dp[x][y].first != -1) { return dp[x][y]; }
        pair<int64_t, int64_t> res1 = solve(x + 1, y);
        pair<int64_t, int64_t> res2 = solve(x + 1, y - x);
        res2.first++;
        if (y < x) {
            return dp[x][y] = res1;
        }
        if (res1.first < res2.first) {
            dp[x][y] = res2;
        } else if (res2.first < res1.first) {
            dp[x][y] = res1;
        } else {
            res1.second += res2.second;
            dp[x][y] = res1;
        }
        return dp[x][y];
    };
    pair<int64_t, int64_t> ans = solve(1, w);
    cout << ans.first << " " << ans.second;
}
