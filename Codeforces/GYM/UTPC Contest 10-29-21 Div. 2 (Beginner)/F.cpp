/**
 *    author:  MaGnsi0
 *    created: 21.11.2021 16:58:09
**/
#include <bits/stdc++.h>

using namespace std;

int solve(int& p, vector<vector<int>>& dp, vector<int>& x, vector<int>& y, vector<int>& t, int a, int b) {
    if (dp[a][b] != -1) {
        return dp[a][b];
    }
    int& res = dp[a][b];
    res = 1;
    for (int i = 0; i < p; ++i) {
        if (i == a) {
            continue;
        }
        for (int j = 0; j < 5; ++j) {
            if (t[a] + b + abs(x[a] - x[i]) + abs(y[a] - y[i]) > t[i] + j) {
                continue;
            }
            res = max(res, 1 + solve(p, dp, x, y, t, i, j));
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, p, sx, sy;
    cin >> n >> p >> sx >> sy;
    vector<int> x(p + 1), y(p + 1), t(p + 1);
    for (int i = 0; i < p; ++i) {
        cin >> t[i] >> x[i] >> y[i];
    }
    x[p] = sx, y[p] = sy, t[p] = 0;
    vector<vector<int>> dp(p + 1, vector<int>(5, -1));
    cout << solve(p, dp, x, y, t, p, 0) - 1;
}
