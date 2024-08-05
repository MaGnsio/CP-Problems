/**
 *    author:  MaGnsi0
 *    created: 02.08.2024 20:29:29
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t X = 30, OO = 2e4, MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int x; cin >> x;
    int m; cin >> m;
    vector<int64_t> fib(X); fib[1] = 1;
    for (int i = 2; i < X; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    int k = n * fib[x] + 1;
    vector<int64_t> f(k, m + 1); f[0] = 0;
    for (int i = 1; i < k; ++i) {
        for (int j = 0; j < X && fib[j] <= i; ++j) {
            f[i] = min(f[i], f[i - fib[j]] + 1);
        }
    }
    vector<vector<int64_t>> dp(n + 1, vector<int64_t>(k)); dp[0][0] = 1;
    for (int i_ = 1; i_ <= x; ++i_) {
        int64_t y = fib[i_];
        for (int j = 0; j < k; ++j) {
            if (y > j) { continue; }
            for (int i = 1; i <= n; ++i) {
                dp[i][j] += dp[i - 1][j - y];
                dp[i][j] %= MOD;
            }
        }
    }
    int64_t ans = 0;
    for (int j = 0; j < k; ++j) {
        ans += (f[j] == m) * dp[n][j];
        ans %= MOD;
    }
    cout << ans;
}
