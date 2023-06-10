/**
 *    author:  MaGnsi0
 *    created: 03.06.2023 18:39:17
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1000;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n + 2);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        a[n + 1] = n + 1;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        function<int(int, int)> solve = [&] (int x, int y) {
            if (y < 0) { return OO; }
            if (x == n + 1) { return int(0); }
            int& ans = dp[x][y];
            if (ans != -1) { return ans; }
            ans = OO;
            for (int j = x + 1; j <= n + 1; ++j) {
                if (a[j] > a[x]) {
                    ans = min(ans, solve(j, y - (j != x + 1)) + (j - x - 1));
                }
            }
            return ans;
        };
        for (int i = 1; i <= n; ++i) {
            cout << solve(0, i) << " ";
        }
        cout << "\n";
    }
}
