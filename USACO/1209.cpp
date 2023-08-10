/**
 *    author:  MaGnsi0
 *    created: 07.08.2023 15:52:48
**/
#include <bits/stdc++.h>

using namespace std;

int fsb(int x) {
    int res = 0;
    while (x) {
        if (x & 1) { break; }
        x /= 2, res++;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<bool>> can(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        bool s = true;
        for (int k = 0; k < n; ++k) {
            int j; cin >> j; --j;
            can[i][j] = s;
            s = s && (j != i);
        }
    }
    vector<vector<int64_t>> dp(n + 1, vector<int64_t>(1 << n, -1));
    function<int64_t(int, int)> solve = [&](int v, int mask) {
        if (mask + 1 == (1 << n)) { return int64_t(1); }
        if (dp[v][mask] != -1) { return dp[v][mask]; }
        int u = fsb(~mask);
        dp[v][mask] = 0;
        if (v == n) {
            dp[v][mask] += solve(u, mask);
        } else {
            for (int i = 0; i < n; ++i) {
                if (mask >> i & 1) { continue; }
                if (can[i][v] == false) { continue; }
                if (i == u) {
                    dp[v][mask] += solve(n, mask | (1 << i));
                } else {
                    dp[v][mask] += solve(i, mask | (1 << i));
                }
            }
        }
        return dp[v][mask];
    };
    int Q;
    cin >> Q;
    while (Q--) {
        string S;
        cin >> S;
        int X = 0, Y = 0;
        for (int i = 0; i < n; ++i) {
            X += (S[i] == 'H') * (1 << i);
            Y += (S[i] == 'G') * (1 << i);
        }
        int64_t ans = solve(n, X) * solve(n, Y);
        cout << ans << "\n";
    }
}
