/**
 *    author:  MaGnsi0
 *    created: 31.10.2023 23:25:06
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 3e3 + 3, OO = 1e14;

int n, a[N], b[N];
int64_t dp[2][2 * N][4];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    if (accumulate(a, a + n, 0) == 0) {
        cout << 0;
        return 0;
    }
    for (int y = -n; y <= n; ++y) {
        for (int z = 0; z < 4; ++z) {
            dp[0][y + n][z] = OO;
        }
    }
    dp[0][min(a[0], n) + n][1] = a[0] + max(a[0] - n, 0);
    dp[0][!!a[0] + n - 1][2] = a[0] + b[0] - !!a[0];
    for (int x = 1; x < n; ++x) {
        for (int y = -n; y <= n; ++y) {
            for (int z = 0; z < 4; ++z) {
                dp[x & 1][y + n][z] = OO;
            }
        }
        for (int y = -n; y <= n; ++y) {
            for (int z = 0; z < 4; ++z) {
                int rem = max(0, y + a[x] - n);
                dp[x & 1][y + (a[x] - rem) + n][z | 1] = min(dp[x & 1][y + (a[x] - rem) + n][z | 1], dp[x & 1 ^ 1][y + n][z] + a[x] + rem);
                dp[x & 1][y + (!!a[x] - 1) + n][z | 2] = min(dp[x & 1][y + (!!a[x] - 1) + n][z | 2], dp[x & 1 ^ 1][y + n][z] + a[x] + b[x] - !!a[x]);
            }
        }
    }
    int64_t ans = OO;
    for (int y = -n; y <= n; ++y) {
        ans = min(ans, dp[n & 1 ^ 1][y + n][3] + max(y, 0));
    }
    cout << ans;
}
