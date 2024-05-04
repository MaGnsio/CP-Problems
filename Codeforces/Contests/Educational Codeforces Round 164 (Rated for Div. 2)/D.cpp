/**
 *    author:  MaGnsi0
 *    created: 13.04.2024 02:52:47
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 5e3 + 5, MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<vector<int64_t>> dp(n, vector<int64_t>(N, -1));
    function<int64_t(int, int)> solve = [&](int j, int sum) {
        if (j == n) { return int64_t(0); }
        if (dp[j][sum] != -1) { return dp[j][sum]; }
        dp[j][sum] = solve(j + 1, sum);
        dp[j][sum] += solve(j + 1, sum + a[j]) + max(a[j], (sum + a[j] + 1) / 2);
        dp[j][sum] %= MOD;
        return dp[j][sum];
    };
    int64_t ans = solve(0, 0);
    cout << ans;
}
