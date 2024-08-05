/**
 *    author:  MaGnsi0
 *    created: 02.06.2024 15:23:04
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int M; cin >> M;
    int N; cin >> N;
    vector<int> X(M), Y(M);
    for (int i = 0; i < M; ++i) {
        cin >> X[i]; X[i]--;
        Y[X[i]] |= 1 << i;
    }
    vector<vector<int64_t>> dp(N, vector<int64_t>(1 << M, -1));
    function<int64_t(int, int)> solve = [&](int j, int need) {
        if (j == N) { return int64_t(1); }
        if (dp[j][need] != -1) { return dp[j][need]; }
        dp[j][need] = 0;
        for (int x = 0; x < M; ++x) {
            if (need >> x & 1) { continue; }
            int _need = (need | (1 << x)) & (((1 << M) - 1) ^ Y[x]);
            dp[j][need] += solve(j + 1, _need);
            dp[j][need] %= MOD;
        }
        return dp[j][need];
    };
    cout << solve(0, 0);
}
