/**
 *    author:  MaGnsi0
 *    created: 25.07.2022 08:41:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int64_t> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    vector<int64_t> B(N);
    for (int i = 0; i < M; ++i) {
        int64_t c, y;
        cin >> c >> y;
        B[c - 1] = y;
    }
    vector<vector<int64_t>> dp(N, vector<int64_t>(N, -1));
    function<int64_t(int, int)> solve = [&](int x, int y) {
        if (x == N) {
            return int64_t(0);
        }
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        dp[x][y] = max(A[x] + B[y] + solve(x + 1, y + 1), solve(x + 1, 0));
        return dp[x][y];
    };
    cout << solve(0, 0);
}
