/**
 *    author:  MaGnsi0
 *    created: 28/09/2021 14:21:42
**/
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;
vector<vector<int>> dp;

int solve(int i, int j) {
    if (i == n || j == k) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int ni = i;
    while (ni < n && a[ni] - a[i] <= 5) {
        ni++;
    }
    dp[i][j] = max(solve(i + 1, j), solve(ni, j + 1) + (ni - i));
    return dp[i][j];
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    cin >> n >> k;
    a = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    dp = vector<vector<int>>(n, vector<int>(k + 1, -1));
    cout << solve(0, 0);
}
