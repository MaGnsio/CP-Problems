/**
 *    author:  MaGnsi0
 *    created: 25.08.2024 15:11:36
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 501, MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<bitset<N>>> conditions(n, vector<bitset<N>>(n, 0));
    for (int i = 0; i < m; ++i) {
        int l; cin >> l; l--;
        int r; cin >> r; r--;
        int x; cin >> x; x--;
        for (int j = r; j < n; ++j) {
            conditions[l][j][x] = 1;
        }
    }
    vector<vector<int64_t>> C(N, vector<int64_t>(N, 0));
    for (int i = 0; i < N; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }
    vector<vector<int64_t>> dp(n, vector<int64_t>(n, -1));
    function<int64_t(int, int)> solve = [&](int L, int R) {
        if (L > R) { return int64_t(1); }
        if (dp[L][R] != -1) { return dp[L][R]; }
        bitset<N> bad = 0;
        for (int l = L; l <= R; ++l) {
            bad = bad | conditions[l][R];
        }
        dp[L][R] = 0;
        for (int put = L; put <= R; ++put) {
            if (bad[put]) { continue; }
            dp[L][R] += solve(L, put - 1) * solve(put + 1, R) % MOD * (R - put < 0 ? int64_t(1) : C[R - L][R - put]) % MOD;
            dp[L][R] %= MOD;
        }
        return dp[L][R];
    };
    int64_t ans = solve(0, n - 1);
    cout << ans;
}
