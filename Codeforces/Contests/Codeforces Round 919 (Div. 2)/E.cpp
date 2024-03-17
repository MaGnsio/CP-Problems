/**
 *    author:  MaGnsi0
 *    created: 18.01.2024 21:14:34
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        vector<vector<int64_t>> dp(n, vector<int64_t>(k, -1));
        function<int64_t(int, int)> solve = [&](int x, int y) {
            if (x == n) { return int64_t(1); }
            if (dp[x][y] != -1) { return dp[x][y]; }
            dp[x][y] = 0;
            for (int add = 0; add < k - y; ++add) {
                if (x + (y + 1) * (add + 1) > n) { break; }
                dp[x][y] += solve(x + (y + 1) * (add + 1), add);
                dp[x][y] %= MOD;
            }
            return dp[x][y];
        };
        int64_t ans = 0;
        for (int y = 0; y < k; ++y) {
            ans += solve(0, y);
            ans %= MOD;
        }
        cout << ans << "\n";
    }
}
