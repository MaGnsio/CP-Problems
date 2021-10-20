/**
 *    author:  MaGnsi0
 *    created: 13/08/2021 22:35:17
**/
#include <bits/stdc++.h>
using namespace std;

const int N = 20;
double dp[1 << N], p[N][N];

int n;

double solve(int mask) {
    double ret = 0;
    if (!isnan(dp[mask])) {
        return dp[mask];
    }
    int cnt = __builtin_popcount(mask) + 1;
    double mp = 2.0 / double(cnt * (cnt - 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (((1 << i) & mask) && !((1 << j) & mask)) {
                ret += mp * p[i][j] * solve(mask | (1 << j));
            }
        }
    }
    return dp[mask] = ret;
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> n;
        memset(dp, -1, sizeof dp);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> p[i][j];
            }
        }
        dp[(1 << n) - 1] = 1.0;
        cout << "Case " << t << ": ";
        for (int i = 0; i < n; ++i) {
            cout << fixed << setprecision(6) << solve(1 << i) << " ";
        }
        cout << "\n";
    }
}
