/**
 *    author:  MaGnsi0
 *    created: 20.08.2024 18:50:35
**/

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 505;

int64_t n, k, MOD;
int64_t F[N], F_[N], C[N][N], dp[N][N];



int64_t power(int64_t b, int64_t p) {
    int64_t res = 1;
    while (p) {
        if (p & 1) { res = res * b % MOD; }
        b = b * b % MOD;
        p /= 2;
    }
    return res;
}

int64_t solve(int level, int adds) {
    if (level == n - 1) { return 1; }
    int64_t& res = dp[level][adds];
    if (res != -1) { return res; }
    res = 0;
    for (int64_t winner_adds = 1; winner_adds <= adds; ++winner_adds) {
        int64_t loser_adds = min(adds - winner_adds, winner_adds - 1);
        res += 2 * solve(level + 1, winner_adds) % MOD * C[level][loser_adds] % MOD;
        res %= MOD;
    }
    return res;
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        cin >> n >> k >> MOD;
        F[0] = F_[0] = 1;
        for (int i = 1; i <= k; ++i) {
            F[i] = F[i - 1] * i % MOD;
            F_[i] = power(F[i], MOD - 2);
        }
        for (int level = 0; level + 1 < n; ++level) {
            for (int adds = 0; adds <= k; ++adds) {
                C[level][adds] = F_[adds];
                int64_t tree_size = power(2, n - level - 1) % MOD;
                for (int i = 0; i < adds; ++i) {
                    C[level][adds] *= (tree_size + i) % MOD;
                    C[level][adds] %= MOD;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[i][j] = -1;
            }
        }
        int64_t ans = solve(0, k);
        cout << ans << "\n";
    }
}
