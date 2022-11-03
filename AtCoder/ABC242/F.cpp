/**
 *    author:  MaGnsi0
 *    created: 15.06.2022 04:25:42
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M, B, W;
    cin >> N >> M >> B >> W;
    vector<vector<int64_t>> C(N * M + 1, vector<int64_t>(N * M + 1, 0));
    for (int i = 0; i <= N * M; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            C[i][j] %= MOD;
        }
    }
    vector<vector<int64_t>> dp1(N + 1, vector<int64_t>(M + 1, 0));
    for (int n = 0; n <= N; ++n) {
        for (int m = 0; m <= M; ++m) {
            for (int i = 0; i <= n; ++i) {
                for (int j = 0; j <= m; ++j) {
                    int64_t X = (((C[n][i] * C[m][j]) % MOD) * C[(n - i) * (m - j)][B]) % MOD;
                    dp1[n][m] += (((i + j) & 1) ? -1 : 1) * X;
                    dp1[n][m] += MOD;
                    dp1[n][m] %= MOD;
                }
            }
        }
    }
    vector<vector<int64_t>> dp2(N + 1, vector<int64_t>(M + 1, 0));
    for (int n = 0; n <= N; ++n) {
        for (int m = 0; m <= M; ++m) {
            for (int i = 0; i <= n; ++i) {
                for (int j = 0; j <= m; ++j) {
                    int64_t X = (((C[n][i] * C[m][j]) % MOD) * C[(n - i) * (m - j)][W]) % MOD;
                    dp2[n][m] += ((i + j) & 1 ? -1 : 1) * X;
                    dp2[n][m] += MOD;
                    dp2[n][m] %= MOD;
                }
            }
        }
    }
    int64_t ans = 0;
    for (int n1 = 0; n1 <= N; ++n1) {
        for (int m1 = 0; m1 <= M; ++m1) {
            for (int n2 = 0; n2 <= N - n1; ++n2) {
                for (int m2 = 0; m2 <= M - m1; ++m2) {
                    int64_t X = ((C[N][n1] * C[M][m1] % MOD) * dp1[n1][m1]) % MOD;
                    int64_t Y = ((C[N - n1][n2] * C[M - m1][m2] % MOD) * dp2[n2][m2]) % MOD;
                    ans += (X * Y) % MOD;
                    ans %= MOD;
                }
            }
        }
    }
    cout << ans;
}
