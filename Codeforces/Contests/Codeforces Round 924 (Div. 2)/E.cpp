/**
 *    author:  MaGnsi0
 *    created: 26.09.2024 20:48:34
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int64_t> dp(N, -1);
    function<int64_t(int)> solve = [&](int sum) {
        if (sum == 0) { return int64_t(0); }
        if (dp[sum] != -1) { return dp[sum]; }
        dp[sum] = 2 * sum;
        for (int64_t m = 2; m * (m - 1) / 2 <= sum; ++m) {
            int64_t take = m * (m - 1) / 2;
            dp[sum] = min(dp[sum], solve(sum - take) + m);
        }
        return dp[sum];
    };
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        int64_t x; cin >> x;
        int64_t y; cin >> y;
        int64_t s; cin >> s;
        bool good = false;
        for (int64_t k = 1; k <= n; ++k) {
            int64_t have = k * x + y * k * (k - 1) / 2 + (n - k) * (x % y);
            if (have > s) { break; }
            int64_t need = s - have;
            if (need % y) { continue; }
            need /= y;
            if (solve(need) > n - k) { continue; }
            vector<int> blocks;
            for (int sum = need; sum != 0; /*_*/) {
                for (int64_t m = 2; m * (m - 1) / 2 <= sum; ++m) {
                    int64_t take = m * (m - 1) / 2;
                    if (solve(sum - take) + m == solve(sum)) {
                        blocks.push_back(m);
                        sum -= take;
                        break;
                    }
                }
            }
            vector<int64_t> ans;
            for (int64_t j = 0, val = x; j < k; ++j, val += y) {
                ans.push_back(val);
            }
            for (int64_t m : blocks) {
                for (int64_t j = 0, val = x % y; j < m; ++j, val += y) {
                    ans.push_back(val);
                }
            }
            while ((int)ans.size() != n) { ans.push_back(x % y); }
            cout << "YES\n";
            for (int64_t val : ans) { cout << val << " "; }
            cout << "\n";
            good = true;
            break;
        }
        if (!good) { cout << "NO\n"; }
    }
}
