/**
 *    author:  MaGnsi0
 *    created: 10.11.2023 17:03:32
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2023;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<vector<int>> rows(N);
    for (int i = 0, x = 1; i < N; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            rows[i].push_back(x++);
        }
    }
    vector<vector<int>> adj(N * N);
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            if (j == 0) {
                adj[rows[i][j]].push_back(rows[i - 1][j]);
            } else if (j == i) {
                adj[rows[i][j]].push_back(rows[i - 1][j - 1]);
            } else {
                adj[rows[i][j]].push_back(rows[i - 1][j]);
                adj[rows[i][j]].push_back(rows[i - 1][j - 1]);
            }
        }
    }
    vector<int64_t> dp(N * N, -1);
    function<int64_t(int)> solve = [&](int x) {
        if (dp[x] != -1) { return dp[x]; }
        dp[x] = 1LL * x * x;
        for (int y : adj[x]) {
            dp[x] += solve(y);
        }
        if (adj[x].size() == 2) {
            dp[x] -= solve(adj[adj[x][1]][0]);
        }
        return dp[x];
    };
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        cout << solve(n) << "\n";
    }
}
