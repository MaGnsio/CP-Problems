/**
 *    author:  MaGnsi0
 *    created: 26/09/2021 19:26:26
**/
#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;

int n, m, k;

vector<long long> v;
vector<vector<long long>> dp(N, vector<long long>(N, -1));

long long solve(int i, int j) {
    if (i - 1 >= n - m || j == k) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    long long x = v[i + m - 1] - (i ? v[i - 1] : 0LL);
    dp[i][j] = max(solve(i + 1, j), solve(i + m, j + 1) + x);
    return dp[i][j];
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    cin >> n >> m >> k;
    v = vector<long long>(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 1; i < n; ++i) {
        v[i] += v[i - 1];
    }
    cout << solve(0, 0);
}
