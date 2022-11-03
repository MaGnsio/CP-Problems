/**
 *    author:  MaGnsi0
 *    created: 25.10.2022 08:45:38
**/
#include <bits/stdc++.h>

using namespace std;

double OO = 1e18;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> Xt(n + 1), Yt(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> Xt[i] >> Yt[i];
    }
    vector<int> Xc(m), Yc(m);
    for (int i = 0; i < m; ++i) {
        cin >> Xc[i] >> Yc[i];
    }
    int k = (n + m + 1);
    vector<vector<double>> dp(k, vector<double>(1 << k, -1));
    function<double(int, int)> D = [&](int i, int j) {
        int x1 = (i <= n ? Xt[i] : Xc[i - n - 1]);
        int y1 = (i <= n ? Yt[i] : Yc[i - n - 1]);
        int x2 = (j <= n ? Xt[j] : Xc[j - n - 1]);
        int y2 = (j <= n ? Yt[j] : Yc[j - n - 1]);
        return sqrt(1.0 * (x1 - x2) * (x1 - x2) + 1.0 * (y1 - y2) * (y1 - y2));
    };
    function<double(int, int)> solve = [&](int j, int mask) {
        int cur_boost = __builtin_popcount(mask >> (n + 1));
        if (__builtin_popcount(mask & ((1 << (n + 1)) - 1)) == n + 1) {
            return D(0, j) / (1 << cur_boost);
        }
        double& ans = dp[j][mask];
        if (ans != -1) {
            return ans;
        }
        ans = OO;
        for (int i = 0; i <= n; ++i) {
            if ((mask >> i) & 1) {
                continue;
            }
            ans = min(ans, D(i, j) / (1 << cur_boost) + solve(i, mask | (1 << i)));
        }
        for (int i = 0; i < m; ++i) {
            if ((mask >> (n + 1 + i)) & 1) {
                continue;
            }
            ans = min(ans, D(n + 1 + i, j) / (1 << cur_boost) + solve(n + 1 + i, mask | (1 << (n + 1 + i))));
        }
        return ans;
    };
    cout << fixed << setprecision(10) << solve(0, 1);
}
