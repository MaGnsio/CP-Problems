/**
 *    author:  MaGnsi0
 *    created: 21.10.2021 17:37:28
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1003;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<long long>> f(N, vector<long long>(N, 0));
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        f[x][y]++;
    }
    vector<vector<long long>> cnt = f;
    {
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cnt[i][j] += cnt[i - 1][j];
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j < N; ++j) {
                cnt[i][j] += cnt[i][j - 1];
            }
        }
    }
    vector<vector<long long>> dp(N, vector<long long>(N));
    {
        for (int i = 1; i < N - 1; ++i) {
            for (int j = 1; j < N - 1; ++j) {
                long long x = cnt[N - 1][N - 1] - cnt[i][N - 1] - cnt[N - 1][j] + cnt[i][j];
                dp[i][j] = (x * f[i][j]);
            }
        }
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[i][j] += dp[i - 1][j];
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j < N; ++j) {
                dp[i][j] += dp[i][j - 1];
            }
        }
    }
    long long res = 0;
    {
        for (int i = 0; i < N - 1; ++i) {
            for (int j = 0; j < N - 1; ++j) {
                long long x = dp[N - 1][N - 1] - dp[N - 1][j] - dp[i][N - 1] + dp[i][j];
                res += (x * f[i][j]);
            }
        }
    }
    cout << res;
}
/*
 * A       B
 *     S
 * D       C
 *
 * S = C - B - D + A
 */
