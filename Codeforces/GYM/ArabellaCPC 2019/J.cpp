/**
 *    author:  MaGnsi0
 *    created: 23.10.2023 02:44:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string n; cin >> n;
    reverse(n.begin(), n.end());
    int m = (int)n.size();
    vector<vector<int>> dp(m, vector<int>(2, -1));
    function<int(int, int)> solve = [&](int x, int y) {
        if (x == m) { return y; }
        if (dp[x][y] != -1) { return dp[x][y]; }
        dp[x][y] = solve(x + 1, 0) + (n[x] - '0') + y;
        dp[x][y] = min(dp[x][y], solve(x + 1, 1) + 9 - (n[x] - '0') - y + 1);
        return dp[x][y];
    };
    int ans = solve(0, 0);
    cout << ans;
}
