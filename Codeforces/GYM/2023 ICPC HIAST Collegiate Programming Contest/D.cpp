/**
 *    author:  MaGnsi0
 *    created: 28.08.2023 20:21:48
**/
#include <bits/stdc++.h>

using namespace std;

int64_t MOD, P, M = 10;

int64_t power(int64_t b, int64_t p = P) {
    if (b == 0) { return 0; }
    int64_t res = 1;
    while (p) {
        if (p & 1) { res = res * b % MOD; }
        b = b * b % MOD;
        p /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        cin >> MOD >> P;
        string s; cin >> s;
        vector<int> cnt(M);
        for (int i = 0; i < n; ++i) {
            cnt[s[i] - '0']++;
        }
        vector<vector<int64_t>> ways(M, vector<int64_t>(n + 1));
        for (int i = 0; i < M; ++i) {
            ways[i][0] = 1;
        }
        for (int j = 1; j <= cnt[0]; ++j) {
            ways[0][j] = 1;
        }
        for (int j = 1; j <= n; ++j) {
            ways[0][j] += ways[0][j - 1];
            ways[0][j] %= MOD;
        }
        for (int i = 1; i < M; ++i) {
            for (int j = 1; j <= n; ++j) {
                int high = j, low = max(j - cnt[i], 0);
                ways[i][j] = (ways[i - 1][high] - (low ? ways[i - 1][low - 1] : 0) + MOD) % MOD;
            }
            for (int j = 1; j <= n; ++j) {
                ways[i][j] += ways[i][j - 1];
                ways[i][j] %= MOD;
            }
        }
        vector<vector<int64_t>> kways(M, vector<int64_t>(n + 1));
        for (int i = 0; i < M; ++i) {
            for (int j = n, k = 0; j >= 0; --j, ++k) {
                kways[i][j] = k * (ways[i][j] - (j ? ways[i][j - 1] : 0) + MOD) % MOD;
            }
            for (int j = 1; j <= n; ++j) {
                kways[i][j] += kways[i][j - 1];
                kways[i][j] %= MOD;
            }
        }
        vector<vector<int64_t>> dp(M, vector<int64_t>(n + 1));
        for (int i = 1; i < M; ++i) {
            for (int j = 1; j <= n; ++j) {
                int high = j, low = max(j - cnt[i], 0);
                dp[i][j] = (dp[i - 1][high] - (low ? dp[i - 1][low - 1] : 0) + MOD) % MOD;
                int64_t val = (kways[i - 1][high] - (low ? kways[i - 1][low - 1] : 0) + MOD) % MOD;
                val -= (n - j) * (ways[i - 1][high] - (low ? ways[i - 1][low - 1] : 0) + MOD) % MOD; 
                val = (val + MOD) % MOD;
                val = power(i) * val % MOD;
                dp[i][j] = (dp[i][j] + val) % MOD;
            }
            for (int j = 1; j <= n; ++j) {
                dp[i][j] += dp[i][j - 1];
                dp[i][j] %= MOD;
            }
        }
        int Q; cin >> Q;
        while (Q--) {
            int low; cin >> low;
            int high; cin >> high;
            cout << (dp[M - 1][high] - dp[M - 1][low - 1] + MOD) % MOD << "\n";
        }
    }
}
