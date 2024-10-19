/**
 *    author:  MaGnsi0
 *    created: 19.10.2024 15:48:04
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 2e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<int> H(m), P(m);
    for (int i = 0; i < m; ++i) {
        char c; cin >> c;
        int p; cin >> p;
        H[i] = (c == 'L' ? 0 : 1);
        P[i] = p;
    }
    vector dp(m, vector<int64_t>(n + 1, -1));
    function<int64_t(int, int)> solve = [&](int j, int x) {
        if (j == m) { return int64_t(0); }
        if (dp[j][x] != -1) { return dp[j][x]; }
        int p = P[j];
        int L = (j == 0 ? 1 : (!H[j - 1] ? P[j - 1] : x));
        int R = (j == 0 ? 2 : (!H[j - 1] ? x : P[j - 1]));
        dp[j][x] = OO;
        if (H[j]) { swap(L, R); }
        //don't move
        if (L == p) {
            dp[j][x] = min(dp[j][x], solve(j + 1, R));
        }
        //counter clock wise
        if (L > p) {
            if (p <= R && R < L) {
                dp[j][x] = min(dp[j][x], solve(j + 1, (p == 1 ? n : p - 1)) + abs(L - p) + abs(R - p) + 1);
            } else {
                dp[j][x] = min(dp[j][x], solve(j + 1, R) + abs(L - p));
            }
        } else {
            if (1 <= R && R < L) {
                dp[j][x] = min(dp[j][x], solve(j + 1, (p == 1 ? n : p - 1)) + n - abs(L - p) + n - abs(R - p) + 1);
            } else if (p <= R && R <= n) {
                dp[j][x] = min(dp[j][x], solve(j + 1, (p == 1 ? n : p - 1)) + n - abs(L - p) + abs(R - p) + 1);
            } else {
                dp[j][x] = min(dp[j][x], solve(j + 1, R) + n - abs(L - p));
            }
        }
        //clock wise
        if (L < p) {
            if (L < R && R <= p) {
                dp[j][x] = min(dp[j][x], solve(j + 1, (p == n ? 1 : p + 1)) + abs(L - p) + abs(R - p) + 1);
            } else {
                dp[j][x] = min(dp[j][x], solve(j + 1, R) + abs(L - p));
            }
        } else {
            if (1 <= R && R <= p) {
                dp[j][x] = min(dp[j][x], solve(j + 1, (p == n ? 1 : p + 1)) + n - abs(L - p) + abs(R - p) + 1);
            } else if (L < R && R <= n) {
                dp[j][x] = min(dp[j][x], solve(j + 1, (p == n ? 1 : p + 1)) + n - abs(L - p) + n - abs(R - p) + 1);
            } else {
                dp[j][x] = min(dp[j][x], solve(j + 1, R) + n - abs(L - p));
            }
        }
        return dp[j][x];
    };
    int64_t ans = solve(0, 0);
    cout << ans;
}
