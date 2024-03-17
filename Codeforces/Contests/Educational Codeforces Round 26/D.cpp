/**
 *    author:  MaGnsi0
 *    created: 06.12.2023 20:04:17
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 202, M = 62;

int n, k, dp[2][N][N * M][2], a[N], b[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int64_t x; cin >> x;
        while (x % 2 == 0) {
            a[i]++;
            x /= 2;
        }
        while (x % 5 == 0) {
            b[i]++;
            x /= 5;
        }
    }
    memset(dp, -1, sizeof dp);
    dp[0][k][0][0] = 0;
    dp[0][k - 1][abs(a[0] - b[0])][a[0] < b[0]] = min(a[0], b[0]);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int x = 0; x < N * M; ++x) {
                for (int y = 0; y < 2; ++y) {
                    int& old = dp[i & 1 ^ 1][j][x][y];
                    if (old == -1) { continue; }
                    int& new1 = dp[i & 1][j][x][y];
                    new1 = max(new1, old);
                    if (j == 0) { continue; }
                    int twos = (y == 0) * x + a[i];
                    int fives = (y == 1) * x + b[i];
                    int& new2 = dp[i & 1][j - 1][abs(twos - fives)][twos < fives];
                    new2 = max(new2, old + min(twos, fives));
                }
            }
        }
    }
    int ans = 0;
    for (int x = 0; x < N * M; ++x) {
        for (int y = 0; y < 2; ++y) {
            ans = max(ans, dp[n & 1 ^ 1][0][x][y]);
        }
    }
    cout << ans;
}
