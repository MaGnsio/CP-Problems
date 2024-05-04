/**
 *    author:  MaGnsi0
 *    created: 11.04.2024 23:47:24
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 11;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int64_t> P3(N, 1);
    for (int i = 1; i < N; ++i) {
        P3[i] = 3LL * P3[i - 1];
    }
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        int k; cin >> k;
        vector<pair<int, int>> path;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char c; cin >> c;
                if (c == '#') {
                    path.emplace_back(i, j);
                }
            }
        }
        vector<int> X(k), Y(k), P(k);
        for (int i = 0; i < k; ++i) {
            cin >> X[i] >> Y[i] >> P[i];
            X[i]--, Y[i]--;
        }
        vector<vector<int64_t>> a(N, vector<int64_t>(k));
        for (int i = 0; i < k; ++i) {
            for (int r = 0; r < N; ++r) {
                for (auto [x, y] : path) {
                    int64_t dx = X[i] - x;
                    int64_t dy = Y[i] - y;
                    a[r][i] += (dx * dx + dy * dy <= r * r);
                }
            }
        }
        vector<vector<int64_t>> dp(k, vector<int64_t>(1 << N, -1));
        function<int64_t(int, int)> solve = [&](int i, int mask) {
            if (i == k) { return int64_t(0); }
            if (dp[i][mask] != -1) { return dp[i][mask]; }
            dp[i][mask] = solve(i + 1, mask);
            for (int r = 0; r < N; ++r) {
                if (mask >> r & 1) { continue; }
                dp[i][mask] = max(dp[i][mask], solve(i + 1, mask | (1 << r)) + a[r][i] * P[i] - P3[r]);
            }
            return dp[i][mask];
        };
        int64_t ans = solve(0, 0);
        cout << ans << "\n";
    }
}
