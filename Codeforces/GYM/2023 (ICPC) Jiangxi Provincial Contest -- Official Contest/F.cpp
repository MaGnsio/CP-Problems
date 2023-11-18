/**
 *    author:  MaGnsi0
 *    created: 13.11.2023 21:41:22
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int64_t> a(n), b(n - 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }
    vector<vector<pair<int64_t, int64_t>>> dp(n, vector<pair<int64_t, int64_t>>(n + 1, {-1, -1}));
    function<pair<int64_t, int64_t>(int64_t, int64_t)> solve = [&](int x, int have) {
        if (x == n - 1) {
            return make_pair(int64_t(0), int64_t(have == 1));
        }
        if (dp[x][have].first != -1) {
            return dp[x][have];
        }
        dp[x][have] = {0, 0};
        if (have && have - 1 <= b[x]) {
            pair<int64_t, int64_t> add = solve(x + 1, have - 1);
            dp[x][have].first += 1LL * add.first * have % MOD;
            dp[x][have].first %= MOD;
            dp[x][have].first += 1LL * add.second * (have - 1) % MOD * (a[x + 1] - a[x]) % MOD * have % MOD;
            dp[x][have].first %= MOD;
            dp[x][have].second += 1LL * add.second * have % MOD;
            dp[x][have].second %= MOD;
        }
        if (have + 1 <= b[x]) {
            pair<int64_t, int64_t> add = solve(x + 1, have + 1);
            dp[x][have].first += add.first;
            dp[x][have].first %= MOD;
            dp[x][have].first += 1LL * add.second * (have + 1) % MOD * (a[x + 1] - a[x]) % MOD;
            dp[x][have].first %= MOD;
            dp[x][have].second += add.second;
            dp[x][have].second %= MOD;
        }
        return dp[x][have];
    };
    int64_t ans = solve(0, 0).first;
    cout << ans;
}
