/**
 *    author:  MaGnsi0
 *    created: 12.05.2023 15:19:52
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 205, MOD = 1e9 + 7;

int n, a[N], ok[N][N], dp[N][N][N][3];

int solve(int i, int j, int k, int turn) {
    if (turn == 0 && i == n) { return j != 0; }
    if (turn == 1 && j == n) { return 0; }
    if (turn == 2 && k == n) { return 0; }
    int& ans = dp[i][j][k][turn];
    if (ans != -1) { return ans; }
    ans = 0;
    if (turn == 0) {
        ans += solve(i + 1, j, k, 0);
        ans %= MOD;
        if (j == 0 || ok[a[j - 1]][a[i]]) {
            ans += solve(i + 1, j, k, 1);
            ans %= MOD;
        }
    } else if (turn == 1) {
        ans += solve(i, j + 1, k, 1);
        ans %= MOD;
        if (a[i - 1] == a[j]) {
            ans += solve(i, j + 1, k, 2);
            ans %= MOD;
        }
    } else {
        ans += solve(i, j, k + 1, 2);
        ans %= MOD;
        if (a[i - 1] == a[k]) {
            ans += solve(i, j, k + 1, 0);
            ans %= MOD;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i]--;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                char c; cin >> c;
                ok[i][j] = c == '1';
            }
        }
        memset(dp, -1, sizeof dp);
        cout << solve(0, 0, 0, 0) % MOD << "\n";
    }
}
