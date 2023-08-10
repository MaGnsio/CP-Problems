/**
 *    author:  MaGnsi0
 *    created: 18.07.2023 18:27:40
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 300, M = 16, MOD = 1e9 + 7;

int n, m;
char a[N][N];
int dp[N][1 << M][2][2];

int solve(int row, int col, int mask, int missed_one, int is_protected) {
    if (row == n) {
        return 1;
    }
    if (col == m) {
        return solve(row + 1, 0, mask, missed_one, 0);
    }
    int& ans = dp[m * row + col][mask][missed_one][is_protected];
    if (ans != -1) {
        return ans;
    }
    ans = 0;
    //put a guard.
    if (a[row][col] != 'x') {
        ans += solve(row, col + 1, mask | (1 << col), missed_one, 1);
        ans %= MOD;
    }
    //put no guard.
    if (a[row][col] == 'x') {
        ans += solve(row, col + 1, mask & ~(1 << col), missed_one, 0);
        ans %= MOD;
    } else if (is_protected || (mask >> col & 1)) {
        ans += solve(row, col + 1, mask, missed_one, is_protected);
        ans %= MOD;
    } else if (!missed_one) {
        ans += solve(row, col + 1, mask, 1, is_protected);
        ans %= MOD;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (m <= n) {
                cin >> a[i][j];
            } else {
                cin >> a[j][i];
            }
        }
    }
    if (n < m) { swap(n, m); }
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0, 0, 0, 0);
}
