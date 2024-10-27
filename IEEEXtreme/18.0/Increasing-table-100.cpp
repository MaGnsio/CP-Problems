/**
 *    author:  MaGnsi0
 *    created: 26.10.2024 04:10:02
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<bool> a(2 * n, true), b(2 * n, true);
    {
        int m; cin >> m;
        while (m--) { int x; cin >> x; b[x - 1] = false; } 
    }
    {
        int m; cin >> m;
        while (m--) { int x; cin >> x; a[x - 1] = false; }
    }
    vector dp(n + 1, vector<int64_t>(n + 1, -1));
    function<int64_t(int, int)> solve = [&](int c1, int c2) {
        if (c1 == n && c2 == n) { return int64_t(1); }
        if (dp[c1][c2] != -1) { return dp[c1][c2]; }
        dp[c1][c2] = 0;
        int x = c1 + c2;
        if (c1 < n && a[x]) {
            dp[c1][c2] += solve(c1 + 1, c2);
            dp[c1][c2] %= MOD;
        }
        if (c2 < n && c2 < c1 && b[x]) {
            dp[c1][c2] += solve(c1, c2 + 1);
            dp[c1][c2] %= MOD;
        }
        return dp[c1][c2];
    };
    int64_t ans = solve(0, 0);
    cout << ans;
}
