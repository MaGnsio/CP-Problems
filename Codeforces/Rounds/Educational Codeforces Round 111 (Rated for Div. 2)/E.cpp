/**
 *    author:  MaGnsi0
 *    created: 21.07.2023 15:21:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    string s;
    cin >> n >> k >> s;
    function<bool(int)> F = [&](int x) {
        if (x == 0) { return true; }
        vector<vector<int>> a(k);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') {
                for (int j = 0; j < k; ++j) {
                    a[j].push_back(i);
                }
            } else {
                a[s[i] - 'a'].push_back(i);
            }
        }
        for (int i = 0; i < k; ++i) {
            sort(a[i].begin(), a[i].end());
        }
        vector<vector<int>> b(k);
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < (int)a[i].size(); ++j) {
                if (j + x - 1 >= (int)a[i].size()) { break; }
                if (a[i][j + x - 1] - a[i][j] + 1 == x) {
                    b[i].push_back(a[i][j]);
                }
            }
            b[i].push_back(n + 1);
        }
        vector<int> dp(1 << k, n + 1);
        dp[0] = 0;
        for (int mask = 0; mask < (1 << k); ++mask) {
            for (int j = 0; j < k; ++j) {
                if (mask >> j & 1) { continue; }
                int res = *lower_bound(b[j].begin(), b[j].end(), dp[mask]);
                dp[mask | (1 << j)] = min(dp[mask | (1 << j)], res + x);
            }
        }
        return dp[(1 << k) - 1] <= n;
    };
    int low = 0, high = n / k, ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (F(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans;
}
