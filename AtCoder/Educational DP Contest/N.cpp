/**
 *    author:  MaGnsi0
 *    created: 29/09/2021 16:50:49
**/
#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> v, f;
vector<vector<long long>> dp;

long long solve(int i, int j) {
    if (i == j) {
        return dp[i][j] = 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    dp[i][j] = LLONG_MAX;
    for (int k = i; k < j; ++k) {
        dp[i][j] = min(dp[i][j], f[j] - (i ? f[i - 1] : 0) + solve(i, k) + solve(k + 1, j));
    }
    return dp[i][j];
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    cin >> n;
    v = f = vector<long long>(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    f[0] = v[0];
    for (int i = 1; i < n; ++i) {
        f[i] += f[i - 1] + v[i];
    }
    dp = vector<vector<long long>>(n, vector<long long>(n, -1));
    cout << solve(0, n - 1);
}
