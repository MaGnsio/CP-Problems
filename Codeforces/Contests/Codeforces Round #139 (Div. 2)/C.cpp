/**
 *    author:  MaGnsi0
 *    created: 07/09/2021 15:31:22
**/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3, OO = 1e7;

int dp[N][N][2], a[N], b[N];

int n, m, x, y;

int solve(int i, int j, int k) {
    if (i == m) {
        return (x <= j && j <= y ? 0 : OO);
    }
    int& ret = dp[i][j][k];
    if (ret != -1) {
        return ret;
    }
    ret = OO;
    if (j <= y) {
        ret = (k ? a[i] : b[i]) + solve(i + 1, j + 1, k);
    }
    if (j >= x && j <= y) {
        ret = min(ret, (!k ? a[i] : b[i]) + solve(i + 1, 1, k ^ 1));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    cin >> n >> m >> x >> y;
    y = min(y, m);
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char x;
            cin >> x;
            a[j] += (x == '#');
            b[j] += (x == '.');
        }
    }
    memset(dp, -1, sizeof dp);
    cout << min(solve(0, 0, 0), solve(0, 0, 1));
}
