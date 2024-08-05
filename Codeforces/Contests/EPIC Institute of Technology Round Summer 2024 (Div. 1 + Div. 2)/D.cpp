/**
 *    author:  MaGnsi0
 *    created: 30.06.2024 18:05:20
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        map<int, int> lst;
        for (int i = 0; i < n; ++i) {
            lst[a[i]] = i;
        }
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        function<int(int, int)> solve = [&](int x, int y) {
            if (x == n) { return 0; }
            if (dp[x][y] != -1) { return dp[x][y]; }
            dp[x][y] = OO;
            //bob will eat this
            if (y) {
                dp[x][y] = min(dp[x][y], solve(x + 1, y - 1));
            }
            //alice will eat this
            dp[x][y] = min(dp[x][y], solve(lst[a[x]] + 1, min(y + 1, n)) + 1);
            return dp[x][y];

        };
        int ans = solve(0, 0);
        cout << ans << "\n";
    }
}
