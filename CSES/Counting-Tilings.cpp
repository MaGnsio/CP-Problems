/**
 *    author:  MaGnsi0
 *    created: 31.01.2022 19:18:15
**/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(m + 1, vector<int>(1 << n, 0));
    dp[0][0] = 1;
    function<void(int, int, int, int)> fit = [&](int cur_row, int cur_col, int mask_cur_col, int mask_next_col) {
        if (cur_row == n) {
            dp[cur_col + 1][mask_next_col] += dp[cur_col][mask_cur_col];
            dp[cur_col + 1][mask_next_col] %= MOD;
            return;
        }
        if ((mask_cur_col >> cur_row) & 1) {
            fit(cur_row + 1, cur_col, mask_cur_col, mask_next_col);
        } else {
            fit(cur_row + 1, cur_col, mask_cur_col, mask_next_col | (1 << cur_row));
            if ((cur_row + 1 < n) && !((mask_cur_col >> (cur_row + 1)) & 1)) {
                fit(cur_row + 2, cur_col, mask_cur_col, mask_next_col);
            }
        }
    };
    for (int cur_col = 0; cur_col < m; ++cur_col) {
        for (int mask_cur_col = 0; mask_cur_col < (1 << n); ++mask_cur_col) {
            fit(0, cur_col, mask_cur_col, 0);
        }
    }
    cout << dp[m][0];
}
