/**
 *    author:  MaGnsi0
 *    created: 29/09/2021 21:53:58
**/
#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int dp[N][N], a[N];

int solve(int i, int j) {
    if (i == j - 1) {
        return dp[i][j] = 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    dp[i][j] = 1e6;
    for (int k = i + 1; k < j; ++k) {
        dp[i][j] = min(dp[i][j], solve(i, k) + solve(k, j) + a[j] - a[i]); 
    }
    return dp[i][j];
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    while (true) {
        int l, n;
        cin >> l;
        if (l == 0) {
            break;
        }
        cin >> n;
        a[0] = 0, a[n + 1] = l;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        memset(dp, -1, sizeof dp);
        cout << "The minimum cutting is " << solve(0, n + 1) << ".\n";
    }
}
