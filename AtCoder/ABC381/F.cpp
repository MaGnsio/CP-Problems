/**
 *    author:  MaGnsi0
 *    created: 24.11.2024 22:39:35
**/
#include <bits/stdc++.h>

using namespace std;

const int M = 20;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<vector<int>> a(M);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x; x--;
        a[x].push_back(i);
    }
    vector<int> dp(1 << M, n); dp[0] = -1;
    for (int mask = 0; mask < (1 << M); ++mask) {
        int j = dp[mask];
        for (int x = 0; x < M; ++x) {
            if (mask >> x & 1) { continue; }
            int i = upper_bound(a[x].begin(), a[x].end(), j) - a[x].begin();
            if (i + 1 >= (int)a[x].size()) { continue; }
            dp[mask | (1 << x)] = min(dp[mask | (1 << x)], a[x][i + 1]);
        }
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << M); ++mask) {
        if (dp[mask] == n) { continue; }
        ans = max(ans, 2 * __builtin_popcount(mask));
    }
    cout << ans;
}
