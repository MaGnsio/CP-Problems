/**
 *    author:  MaGnsi0
 *    created: 11.04.2023 00:42:33
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e7, MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, m;
    cin >> n >> m;
    vector<vector<int64_t>> a(2, vector<int64_t>(n));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<pair<int64_t, int64_t>>> b(2);
    for (int i = 0; i < n; ++i) {
        b[i & 1].emplace_back(a[0][i], a[1][i]);
    }
    function<int64_t(int64_t, int64_t)> power = [&](int64_t b, int64_t p) {
        if (b == 0) { return int64_t(0); }
        int64_t ans = 1;
        while (p) {
            if (p & 1) { ans = ans * b % MOD; }
            b = b * b % MOD;
            p /= 2;
        }
        return ans;
    };
    function<int64_t(int64_t)> F = [&](int64_t x) {
        int64_t L = max(x - m, int64_t(1));
        int64_t R = min(m, x - 1);
        return max(R - L + 1, int64_t(0));
    };
    function<int64_t(int j)> solve = [&](int j) {
        int k = (int)b[j].size();
        int64_t empty = 0, sum = 0, mn = OO, mx = 0;
        for (int i = 0; i < k; ++i) {
            empty += b[j][i].first == 0 && b[j][i].second == 0;
            if (b[j][i].first && b[j][i].second) {
                if (sum == 0) {
                    sum = b[j][i].first + b[j][i].second;
                } else if (sum != b[j][i].first + b[j][i].second) {
                    return int64_t(0);
                }
            }
            if (b[j][i].first) {
                mn = min(mn, b[j][i].first);
                mx = max(mx, b[j][i].first);
            }
            if (b[j][i].second) {
                mn = min(mn, b[j][i].second);
                mx = max(mx, b[j][i].second);
            }
        }
        if (sum) {
            return (sum - mn <= m && sum - mx > 0 ? power(F(sum), empty) : 0);
        }
        int64_t ans = 0;
        for (int64_t i = 2; i <= 2 * m; ++i) {
            if (empty == k || (i - mn <= m && i - mx > 0)) {
                ans += power(F(i), empty);
                ans %= MOD;
            }
        }
        return ans;
    };
    cout << solve(0) * solve(1) % MOD << "\n";
}
