/**
 *    author:  MaGnsi0
 *    created: 14.06.2023 03:15:29
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first >> a[i].second;
        }
        sort(a.begin(), a.end());
        vector<int> b(n + 1, -1);
        for (int i = 0; i < n; ++i) {
            b[i + 1] = a[i].second;
        }
        sort(b.begin(), b.end());
        b.resize(unique(b.begin(), b.end()) - b.begin());
        int m = (int)b.size();
        map<int, int> mp;
        for (int i = 0; i < m; ++i) {
            mp[b[i]] = i;
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2, -1)));
        function<int(int, int, int)> solve = [&](int x, int y, int z) {
            if (x == n) {
                return z * OO;
            }
            if (dp[x][y][z] != -1) {
                return dp[x][y][z];
            }
            dp[x][y][z] = solve(x + 1, y, z) + 1;
            if (z == 0 && a[x].first > b[y]) {
                dp[x][y][z] = min(dp[x][y][z], solve(x + 1, max(y, mp[a[x].second]), 1));
            }
            if (z == 1 && a[x].first <= b[y]) {
                dp[x][y][z] = min(dp[x][y][z], solve(x + 1, max(y, mp[a[x].second]), 0));
            }
            return dp[x][y][z];
        };
        int ans = solve(0, 0, 0);
        cout << ans << "\n";
    }
}
