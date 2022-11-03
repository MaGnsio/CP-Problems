/**
 *    author:  MaGnsi0
 *    created: 11.09.2022 19:02:23
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    while ((cin >> n) && n) {
        cin >> m;
        vector<int> a(m + 2), b(m + 2);
        for (int i = 0; i < m + 2; ++i) {
            cin >> a[i] >> b[i];
        }
        vector<vector<int>> dp((1 << (m + 2)), vector<int>(7, -1));
        function<int(int, int)> solve = [&](int mask, int last) {
            if (__builtin_popcount(mask) == n + 1) {
                return int(last == a[1]);
            }
            if (dp[mask][last] != -1) {
                return dp[mask][last];
            }
            dp[mask][last] = 0;
            for (int i = 2; i < m + 2; ++i) {
                if (!((mask >> i) & 1)) {
                    if (a[i] == last) {
                        dp[mask][last] |= solve(mask | (1 << i), b[i]);
                    }
                    if (b[i] == last) {
                        dp[mask][last] |= solve(mask | (1 << i), a[i]);
                    }
                }
            }
            return dp[mask][last];
        };
        cout << (solve(1, b[0]) ? "YES" : "NO") << "\n";
    }
}
