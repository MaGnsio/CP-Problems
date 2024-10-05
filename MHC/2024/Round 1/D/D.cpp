/**
 *    author:  MaGnsi0
 *    created: 05.10.2024 21:32:32
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t M = 11, MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        string s; cin >> s;
        int n = (int)s.size();
        int k; cin >> k;
        vector dp(n, vector<int64_t>(M, -1));
        function<int64_t(int, int)> solve = [&](int i, int j) {
            if (i == n) { return int64_t(1); }
            if (dp[i][j] != -1) { return dp[i][j]; }
            dp[i][j] = 0;
            for (int c = 1; c <= 26; ++c) {
                int c1 = c / 10;
                int c2 = c % 10;
                if (c1 == 0) {
                    bool ok1 = (j == M - 1 ? (s[i] == '?' || s[i] - '0' == c2) : c2 == j);
                    if (ok1) {
                        dp[i][j] = max(dp[i][j], solve(i + 1, M - 1));
                    }
                } else if (i + 1 < n) {
                    bool ok1 = (j == M - 1 ? (s[i] == '?' || s[i] - '0' == c1) : c1 == j);
                    bool ok2 = (s[i + 1] == '?' || s[i + 1] - '0' == c2);
                    if (ok1 && ok2) {
                        dp[i][j] = max(dp[i][j], solve(i + 1, c2) + solve(i + 2, M - 1) % MOD);
                    }
                }
            }
            return dp[i][j];
        };
        vector dp2(n, vector<int64_t>(M, -1));
        function<int64_t(int, int)> solve2 = [&](int i, int j) {
            if (i == n - 1) { return int64_t(1); }
            if (dp2[i][j] != -1) { return dp2[i][j]; }
            dp2[i][j] = 0;
            int64_t max_splits = solve(i, j);
            for (int c2 = 0; c2 < M - 1; ++c2) {
                if (s[i + 1] != '?' && s[i + 1] - '0' != c2) { continue; }
                int64_t total = ((j > 0 ? solve(i + 1, c2) : 0) + ((j > 0) && (1 <= 10 * j + c2) && (10 * j + c2 <= 26) ? solve(i + 2, M - 1) : 0)) % MOD;
                if (total == max_splits) {
                    dp2[i][j] += solve2(i + 1, c2);
                    dp2[i][j] = min(dp2[i][j], int64_t(k));
                }
            }
            return dp2[i][j];
        };
        string ans = "";
        function<void(int, int, int)> build = [&](int i, int need, int allowed) {
            if (i == n) { return; }
            int64_t max_splits = solve(i, M - 1);
            for (int d = M - 2; d >= 0; --d) {
                if (!(allowed >> d & 1)) { continue; }
                if (s[i] != '?' && s[i] - '0' != d) { continue; }
                if (solve(i, d) != max_splits) { continue; }
                if (solve2(i, d) >= need) {
                    ans += char('0' + d);
                    int nallowed = 0;
                    if (i != n - 1) {
                        for (int c2 = 0; c2 < M - 1; ++c2) {
                            if (s[i + 1] != '?' && s[i + 1] - '0' != c2) { continue; }
                            int64_t total = ((d > 0 ? solve(i + 1, c2) : 0) + ((d > 0) && (1 <= 10 * d + c2) && (10 * d + c2 <= 26) ? solve(i + 2, M - 1) : 0)) % MOD;
                            if (total == max_splits) {
                                nallowed |= (1 << c2);
                            }
                        }
                    }
                    build(i + 1, need, nallowed);
                    break;
                }
                need -= solve2(i, d);
            }
        };
        build(0, k, (1LL << M) - 1);
        int64_t max_splits = solve(0, M - 1);
        cout << ans << " " << max_splits << "\n";
    }
}
