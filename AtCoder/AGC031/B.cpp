/**
 *    author:  MaGnsi0
 *    created: 22.06.2023 14:09:30
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 2e5 + 5, MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> b(N);
    for (int i = 0; i < n; ++i) {
        b[a[i]].push_back(i);
    }
    vector<int64_t> dp(n, -1);
    function<int64_t(int)> solve = [&](int j) {
        if (j == n) { return (int64_t)1; }
        if (dp[j] != -1) { return dp[j]; }
        auto it = upper_bound(b[a[j]].begin(), b[a[j]].end(), j);
        dp[j] = 0;
        if (it != b[a[j]].end() && *it != j + 1) {
            int x = *it;
            dp[j] += solve(x);
            dp[j] %= MOD;
        }
        dp[j] += solve(j + 1);
        dp[j] %= MOD;
        return dp[j];
    };
    int64_t ans = solve(0);
    cout << ans;
}
