/**
 *    author:  MaGnsi0
 *    created: 14.10.2024 18:01:42
**/
#include <bits/stdc++.h>

using namespace std;

const int M = 5e3 + 5;

int n, m, k = 0, dp[M][M], hcheck[M][M], icheck[M][M], points[M];
int64_t sump[M];

int solve(int j, int h) {
    if (j == k) { return 0; }
    if (dp[j][h] != -1) { return dp[j][h]; }
    int i = (j ? sump[j - 1] : 0) - h;
    dp[j][h] = 0;
    for (int add_h = 0; add_h <= points[j]; ++add_h) {
        int new_h = h + add_h;
        int new_i = i + (points[j] - add_h);
        int vh = hcheck[j][new_h];
        int vi = icheck[j][new_i];
        dp[j][h] = max(dp[j][h], solve(j + 1, new_h) + vh + vi);
    }
    return dp[j][h];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(hcheck, 0, sizeof hcheck);
    memset(icheck, 0, sizeof icheck);
    memset(points, 0, sizeof points);
    memset(sump, 0, sizeof sump);
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    for (int i = 0, last = -2; i < n; ++i) {
        int x; cin >> x;
        if (x == 0) {
            if (last == 0) {
                points[k - 1]++;
            } else {
                k++;
                points[k - 1]++;
            }
            last = 0;
        } else if (x < 0) {
            if (last == -2) { continue; }
            hcheck[k - 1][-x]++;
            last = -1;
        } else {
            if (last == -2) { continue; }
            icheck[k - 1][x]++;
            last = -1;
        }
    }
    for (int i = 0; i < k; ++i) {
        for (int j = 1; j < M; ++j) {
            hcheck[i][j] += hcheck[i][j - 1];
            icheck[i][j] += icheck[i][j - 1];
        }
    }
    for (int i = 0; i < k; ++i) {
        sump[i] = (i ? sump[i - 1] : 0) + points[i];
    }
    int ans = solve(0, 0);
    cout << ans << "\n";
}
