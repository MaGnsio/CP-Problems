/**
 *    author:  MaGnsi0
 *    created: 10.01.2023 00:18:51
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 2 * 300 * 300 + 10, O = 300 * 300, MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int64_t>> dp(n, vector<int64_t>(N, -1));
    function<int64_t(int, int)> solve = [&](int i, int x) {
        if (i == n - 1) {
            return int64_t(1);
        }
        int64_t& res = dp[i][x + O];
        if (res != -1) {
            return res;
        }
        if (x) {
            res = solve(i + 1, a[i + 1] + x) + solve(i + 1, a[i + 1] - x);
            res %= MOD;
        } else {
            res = solve(i + 1, a[i + 1]);
            res %= MOD;
        }
        return res;
    };
    int64_t ans = solve(1, a[1]);
    cout << ans;
}
