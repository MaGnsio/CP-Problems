/**
 *    author:  MaGnsi0
 *    created: 25.01.2024 21:53:21
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t D; cin >> D;
    int64_t R; cin >> R;
    vector<vector<pair<int64_t, int64_t>>> dp(D, vector<pair<int64_t, int64_t>>(R * R + 1, {-1, -1}));
    function<pair<int64_t, int64_t>(int, int)> solve = [&](int d, int r) {
        if (d == D) { return make_pair(0LL, 1LL); }
        pair<int64_t, int64_t>& res = dp[d][r];
        if (res.first != -1) { return res; }
        res = {0, 0};
        for (int x = -R; x <= R; ++x) {
            if (r + x * x > R * R) { continue; }
            pair<int64_t, int64_t> add = solve(d + 1, r + x * x);
            res.first += add.first; res.first %= MOD;
            res.first += abs(x) * add.second % MOD; res.first %= MOD;
            res.second += add.second; res.second %= MOD;
        }
        return res;
    };
    int64_t ans = solve(0, 0).first;
    cout << ans;
}
