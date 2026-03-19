/**
 *    author:  MaGnsi0
 *    created: 12.01.2026 17:23:14
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        map<int, int> dp;
        function<int(int)> solve = [&](int x) {
            if (dp.count(x)) { return dp[x]; }
            if (x == k) { return 0; }
            if (x < k) { return OO; }
            dp[x] = OO;
            dp[x] = min(dp[x], solve(x / 2) + 1);
            dp[x] = min(dp[x], solve((x + 1) / 2) + 1);
            return dp[x];
        };
        int ans = solve(n);
        cout << (ans == OO ? -1 : ans) << "\n";
    }
}
