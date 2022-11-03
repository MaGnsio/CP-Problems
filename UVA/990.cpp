/**
 *    author:  MaGnsi0
 *    created: 06.09.2022 22:55:33
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T, W;
    bool first = false;
    while (cin >> T >> W) {
        int n;
        cin >> n;
        vector<int64_t> d(n), v(n);
        for (int i = 0; i < n; ++i) {
            cin >> d[i] >> v[i];
        }
        vector<vector<int64_t>> dp(n, vector<int64_t>(T + 1, -1));
        function<int64_t(int, int)> solve = [&](int x, int y) {
            if (x == n) {
                return int64_t(0);
            }
            if (dp[x][y] != -1) {
                return dp[x][y];
            }
            dp[x][y] = solve(x + 1, y);
            if (3 * W * d[x] <= y) {
                dp[x][y] = max(dp[x][y], v[x] + solve(x + 1, y - 3 * W * d[x]));
            }
            return dp[x][y];
        };
        vector<int> a;
        function<void(int, int)> build = [&](int x, int y) {
            if (x == n) {
                return;
            }
            if (3 * W * d[x] > y) {
                build(x + 1, y);
            } else if (solve(x + 1, y) > v[x] + solve(x + 1, y - 3 * W * d[x])) {
                build(x + 1, y);
            } else {
                a.push_back(x);
                build(x + 1, y - 3 * W * d[x]);
            }
        };
        if (first) {
            cout << "\n";
        }
        first = true;
        build(0, T);
        cout << solve(0, T) << "\n";
        cout << (int)a.size() << "\n";
        for (int i = 0; i < (int)a.size(); ++i) {
            cout << d[a[i]] << " " << v[a[i]] << "\n";
        }
    }
}
