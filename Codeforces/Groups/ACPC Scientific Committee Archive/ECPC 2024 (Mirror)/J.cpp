/**
 *    author:  MaGnsi0
 *    created: 27.07.2024 21:46:11
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 1e6 + 6, OO = 1e17;

int n;
int64_t a[N], dp[N][3][2][2];

int64_t solve(int j, int x, int y, int z) {
    if (j == -1) {
        return ((x != 0) && (y ^ z == 0) ? 0 : -OO);
    }
    int64_t& res = dp[j][x][y][z];
    if (res != -1) { return res; }
    res = 0;
    if (x == 0) {
        res = max(res, solve(j - 1, x, y, z));
        res = max(res, solve(j - 1, 1, y, z) + a[j]);
        if (z == 0) {
            res = max(res, solve(j - 1, x, y, 1) + a[j]);
        }
        if (y == 0) {
            res = max(res, solve(j - 1, 1, 1, z));
        }
    } else if (x == 1) {
        res = max(res, solve(j - 1, x, y, z) + a[j]);
        res = max(res, solve(j - 1, 2, y, z));
        if (y == 0) {
            res = max(res, solve(j - 1, x, 1, z));
            res = max(res, solve(j - 1, 2, 1, z));
        }
    } else {
        res = max(res, solve(j - 1, x, y, z));
        if (z == 0) {
            res = max(res, solve(j - 1, x, y, 1) + a[j]);
        }
    }
    return res;

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cout << solve(i, 0, 0, 0) << " ";
    }
}
