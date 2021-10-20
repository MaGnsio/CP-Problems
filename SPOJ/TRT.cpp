/**
 *    author:  MaGnsi0
 *    created: 27/09/2021 13:21:05
**/
#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> a;
vector<vector<long long>> dp;

long long solve(int i, int j) {
    if (i == j) {
        return n * a[i];
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int x = n - j + i;
    dp[i][j] = max(x * a[i] + solve(i + 1, j), x * a[j] + solve(i, j - 1));
    return dp[i][j];
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    cin >> n;
    a = vector<long long>(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    dp = vector<vector<long long>>(n, vector<long long>(n, -1));
    cout << solve(0, n - 1);
}
