/**
 *    author:  MaGnsi0
 *    created: 29.06.2023 17:49:30
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s, low, high;
        cin >> s;
        int n = (int)s.size(), m;
        cin >> m >> low >> high;
        vector<set<int>> a(10);
        for (int i = 0; i < n; ++i) {
            a[s[i] - '0'].insert(i);
        }
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m, vector<int>(2, -1)));
        function<int(int, int, int)> solve = [&](int i, int j, int k) {
            if (j == m) { return k; }
            int& ans = dp[i][j][k];
            if (ans != -1) { return ans; }
            ans = 0;
            for (int c = low[j] - '0'; c <= high[j] - '0'; ++c) {
                if (k == 1) {
                    ans = max(ans, solve(n, j + 1, 1));
                } else {
                    auto it = a[c].lower_bound(i);
                    if (it == a[c].end()) {
                        ans = max(ans, solve(n, j + 1, 1));
                    } else {
                        ans = max(ans, solve(*it + 1, j + 1, 0));
                    }
                }
            }
            return ans;
        };
        cout << (solve(0, 0, 0) ? "YES" : "NO") << "\n";
    }
}
