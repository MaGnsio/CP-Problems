/**
 *    author:  MaGnsi0
 *    created: 21.12.2022 16:32:21
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 200, MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<vector<int64_t>> C(N, vector<int64_t>(N));
    for (int i = 0; i < N; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            C[i][j] %= MOD;
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n, x, y, i, j;
        cin >> n >> i >> j >> x >> y;
        if (x > y) {
            swap(x, y);
            swap(i, j);
            i = n - i + 1;
            j = n - j + 1;
        }
        if (y == n) {
            if (1 < j && j < n) {
                int64_t ans = C[x - 1][i - 1];
                ans %= MOD;
                ans *= C[y - x - 1][j - i - 1];
                ans %= MOD;
                cout << ans << "\n";
            } else {
                cout << 0 << "\n";
            }
            continue;
        }
        int64_t ans = 0;
        for (int k = i + 1; k < j; ++k) {
            if (n - j - (x - i) < 0) { continue; }
            int64_t val = C[x - 1][i - 1];
            val %= MOD;
            val *= C[n - y - 1][j - k - 1];
            val %= MOD;
            val *= C[y - x - 1][n - j - (x - i)];
            val %= MOD;
            ans += val;
            ans %= MOD;
        }
        for (int k = j + 1; k < n; ++k) {
            int64_t val = C[x - 1][i - 1];
            val %= MOD;
            val *= C[y - x - 1][j - i - 1];
            val %= MOD;
            val *= C[n - y - 1][k - j - 1];
            val %= MOD;
            ans += val;
            ans %= MOD;
        }
        cout << ans << "\n";
    }
}
