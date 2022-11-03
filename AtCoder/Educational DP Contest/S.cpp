/**
 *    author:  MaGnsi0
 *    created: 20.09.2022 21:04:05
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int d;
    string k;
    cin >> k >> d;
    int n = (int)k.size();
    vector<vector<vector<int64_t>>> dp(n, vector<vector<int64_t>>(d, vector<int64_t>(2, -1)));
    function<int64_t(int, int, int)> solve = [&](int j, int x, int y) {
        if (j == n) {
            return int64_t(x == 0);
        }
        int64_t& ans = dp[j][x][y];
        if (ans != -1) {
            return ans;
        }
        ans = 0;
        if (y) {
            ans += solve(j + 1, (x + k[j] - '0') % d, 1);
            ans %= MOD;
            for (int i = 0; i < k[j] - '0'; ++i) {
                ans += solve(j + 1, (x + i) % d, 0);
                ans %= MOD;
            }
        } else {
            for (int i = 0; i < 10; ++i) {
                ans += solve(j + 1, (x + i) % d, 0);
                ans %= MOD;
            }
        }
        return ans;
    };
    cout << (solve(0, 0, 1) - 1 + MOD) % MOD;
}
