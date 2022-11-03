/**
 *    author:  MaGnsi0
 *    created: 21.09.2022 23:01:05
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 15;
const int dx[4] = {-2, -2, 1, -1};
const int dy[4] = {1, -1, -2, -2};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<vector<int>> dp(N, vector<int>(N, -1));
    function<int(int, int)> solve = [&](int x, int y) {
        if (x < 0 || x >= N) {
            return 1;
        }
        if (y < 0 || y >= N) {
            return 1;
        }
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        dp[x][y] = 0;
        for (int i = 0; i < 4; ++i) {
            dp[x][y] |= !solve(x + dx[i], y + dy[i]);
        }
        return dp[x][y];
    };
    int T;
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        cout << (solve(x - 1, y - 1) ? "First" : "Second") << "\n";
    }
}
