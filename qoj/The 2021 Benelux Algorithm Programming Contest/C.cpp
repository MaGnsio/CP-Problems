/**
 *    author:  MaGnsi0
 *    created: 05.10.2023 18:24:26
**/
#include <bits/stdc++.h>

using namespace std;

bool test(int cur_mask, int last_mask, string row1, string row2) {
    for (int i = 0; i < (int)row1.size(); ++i) {
        if (row1[i] == '.') { continue; }
        if (cur_mask >> i & 1) { continue; }
        return false;
    }
    for (int i = 0; i < (int)row1.size(); ++i) {
        if (row2[i] == '.') { continue; }
        if (cur_mask >> i & 1) { continue; }
        return false;
    }
    for (int i = 0; i < (int)row1.size(); ++i) {
        if (!(cur_mask >> i & 1)) { continue; }
        if ((last_mask >> i & 1) || (last_mask >> (i + 1) & 1)) {
            i++;
            continue;
        }
        return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    reverse(a.begin(), a.end());
    map<int, int> I, J;
    function<void(int, int)> generate_masks = [&](int mask, int j) {
        if (j == m) {
            J[(int)I.size()] = mask;
            I[mask] = (int)I.size();
            return;
        }
        generate_masks(mask, j + 1);
        if (j + 1 < m) {
            generate_masks(mask + (1 << j) + (1 << (j + 1)), j + 2);
        }
    };
    generate_masks(0, 0);
    int k = (int)I.size();
    vector<vector<int64_t>> dp(n, vector<int64_t>(k, -1));
    function<int64_t(int, int)> solve = [&](int row, int last_mask) {
        if (row == n) { return int64_t(0); }
        if (dp[row][last_mask] != -1) {
            return dp[row][last_mask];
        }
        dp[row][last_mask] = 5000;
        for (auto [mask, j] : I) {
            if (test(mask, J[last_mask], a[row], a[row + 1])) {
                dp[row][last_mask] = min(dp[row][last_mask], solve(row + 2, j) + __builtin_popcount(mask) / 2);
            }
        }
        return dp[row][last_mask];
    };
    cout << solve(0, I[(1 << m) - 1]);
}
