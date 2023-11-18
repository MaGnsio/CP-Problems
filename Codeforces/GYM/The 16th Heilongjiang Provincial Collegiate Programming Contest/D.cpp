/**
 *    author:  MaGnsi0
 *    created: 11.10.2023 20:19:07
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1000003;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int64_t>> dp(n, vector<int64_t>(n, -1));
    function<int64_t(int, int)> solve = [&](int low, int high) {
        if (low >= high) { return int64_t(0); }
        if (dp[low][high] != -1) { return dp[low][high]; }
        dp[low][high] = 0;
        int64_t cur_sum = 1;
        vector<int64_t> sum(high - low + 2, 1);
        for (int i = high - low; i >= 0; --i) {
            sum[i] = a[low + i] * sum[i + 1];
            sum[i] %= MOD;
        }
        for (int x = low; x < high; ++x) {
            cur_sum *= a[x];
            cur_sum %= MOD;
            int64_t score = (cur_sum - sum[x - low + 1]) * (cur_sum - sum[x - low + 1]); 
            dp[low][high] = max(dp[low][high], solve(low, x) + solve(x + 1, high) + score);
        }
        return dp[low][high];
    };
    cout << solve(0, n - 1);
}
