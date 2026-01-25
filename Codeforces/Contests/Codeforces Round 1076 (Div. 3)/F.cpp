/**
 *    author:  MaGnsi0
 *    created: 25.01.2026 17:14:19
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e16;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        set<int64_t> X_;
        map<int64_t, int64_t> Y1_, Y2_;
        function<void(int64_t, int64_t)> process_point = [&](int64_t x, int64_t y) {
            X_.insert(x);
            if (Y1_.count(x)) { Y1_[x] = min(Y1_[x], y); }
            else { Y1_[x] = y; }
            if (Y2_.count(x)) { Y2_[x] = max(Y2_[x], y); }
            else { Y2_[x] = y; }
        };
        {
            int x, y;
            cin >> x >> y; process_point(x, y);
            cin >> x >> y; process_point(x, y);
        }
        {
            vector<int> x(n), y(n);
            for (int i = 0; i < n; ++i) {
                cin >> x[i];
            }
            for (int i = 0; i < n; ++i) {
                cin >> y[i];
            }
            for (int i = 0; i < n; ++i) {
                process_point(x[i], y[i]);
            }
        }
        n = (int)X_.size();
        vector<int64_t> X, Y1, Y2;
        for (int64_t x : X_) {
            X.push_back(x);
            Y1.push_back(Y1_[x]);
            Y2.push_back(Y2_[x]);
        }
        vector dp(n, vector<int64_t>(2, -1));
        function<int64_t(int, int)> solve = [&](int i, int j) {
            if (i == n - 1) { return int64_t(0); }
            if (dp[i][j] != -1) { return dp[i][j]; }
            dp[i][j] = OO;
            int64_t y = (j == 0 ? Y2[i] : Y1[i]);
            dp[i][j] = min(dp[i][j], abs(X[i] - X[i + 1]) + abs(Y1[i] - Y2[i]) + abs(y - Y1[i + 1]) + solve(i + 1, 0));
            dp[i][j] = min(dp[i][j], abs(X[i] - X[i + 1]) + abs(Y1[i] - Y2[i]) + abs(y - Y2[i + 1]) + solve(i + 1, 1));
            return dp[i][j];
        };
        int64_t ans = solve(0, 0);
        cout << ans << "\n";
    }
}
