/**
 *    author:  MaGnsi0
 *    created: 18.05.2023 16:49:32
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= m;
    }
    int k;
    cin >> k;
    vector<int64_t> ans(k);
    vector<tuple<int, int, int>> queries;
    for (int i = 0; i < k; ++i) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            ans[i] = (a[l - 1] == 0) + 1;
        } else {
            queries.emplace_back(l - 1, r - 1, i);
        }
    }
    function<void(int, int, vector<tuple<int, int, int>>& b)> solve = [&](int low, int high, vector<tuple<int, int, int>>& b) {
        if (low >= high || b.empty()) { return; }
        int mid = (low + high + 1) / 2;
        vector<tuple<int, int, int>> x, y, z;
        for (auto [l, r, j] : b) {
            if (r < mid) {
                x.emplace_back(l, r, j);
            } else if (l >= mid) {
                z.emplace_back(l, r, j);
            } else {
                y.emplace_back(l, r, j);
            }
        }
        solve(low, mid - 1, x);
        solve(mid, high, z);
        if (y.empty()) { return; }
        vector<vector<int64_t>> pdp(high - mid + 1, vector<int64_t>(m, 0));
        vector<vector<int64_t>> sdp(mid - low, vector<int64_t>(m, 0));
        pdp[0][0]++; pdp[0][a[mid]]++;
        for (int i = mid + 1; i <= high; ++i) {
            for (int j = 0; j < m; ++j) {
                pdp[i - mid][j] += pdp[i - mid - 1][j];
                pdp[i - mid][j] %= MOD;
                pdp[i - mid][(j + a[i]) % m] += pdp[i - mid - 1][j];
                pdp[i - mid][(j + a[i]) % m] %= MOD;
            }
        }
        sdp[(mid - 1) - low][0]++, sdp[(mid - 1) - low][a[mid - 1]]++;
        for (int i = mid - 2; i >= low; --i) {
            for (int j = 0; j < m; ++j) {
                sdp[i - low][j] += sdp[i - low + 1][j];
                sdp[i - low][j] %= MOD;
                sdp[i - low][(j + a[i]) % m] += sdp[i - low + 1][j];
                sdp[i - low][(j + a[i]) % m] %= MOD;
            }
        }
        for (auto [l, r, j] : y) {
            for (int i = 0; i < m; ++i) {
                ans[j] += pdp[r - mid][i] * sdp[l - low][(m - i) % m] % MOD;
                ans[j] %= MOD;
            }
        }
    };
    solve(0, n - 1, queries);
    for (int i = 0; i < k; ++i) {
        cout << ans[i] << "\n";
    }
}
