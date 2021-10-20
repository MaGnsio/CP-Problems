/**
 *    author:  MaGnsi0
 *    created: 07/09/2021 22:32:31
**/
#include <bits/stdc++.h>
using namespace std;

const int shift = 100000, N = 200001, OO = 1e9;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        b[i] *= k;
    }
    vector<vector<int>> dp(n + 1, vector<int>(N, -OO));
    dp[0][shift] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < N; ++j) {
            if (dp[i][j] >= 0) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                dp[i + 1][j + a[i] - b[i]] = max(dp[i + 1][j + a[i] - b[i]], dp[i][j] + a[i]);
            }
        }
    }
    cout << (dp[n][shift] <= 0 ? -1 : dp[n][shift]);
}
