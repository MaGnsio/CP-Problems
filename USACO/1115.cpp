/**
 *    author:  MaGnsi0
 *    created: 03.08.2024 19:58:25
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 40;

string base_3(int64_t n) {
    string m = "";
    while (n) {
        m += char('0' + (n % 3));
        n /= 3;
    }
    while ((int)m.size() < N) { m += "0"; }
    return m;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t d; cin >> d; string D = base_3(d);
        int64_t x; cin >> x; string X = base_3(x);
        int64_t y; cin >> y; string Y = base_3(y);
        vector<vector<vector<vector<int64_t>>>> dp(N, vector<vector<vector<int64_t>>>(3, vector<vector<int64_t>>(3, vector<int64_t>(2, -1))));
        function<int64_t(int, int, int, int)> solve = [&](int j, int carry_x, int carry_y, int need_less) {
            if (j == N) { return int64_t(carry_x == 0 && carry_y == 0 && need_less == 0); }
            int64_t& res = dp[j][carry_x][carry_y][need_less];
            if (res != -1) { return res; }
            res = 0;
            for (int b = 0; b < 3; ++b) {
                int bx = (b + carry_x + X[j] - '0') % 3;
                int by = (b + carry_y + Y[j] - '0') % 3;
                if ((bx & 1) != (by & 1)) { continue; }
                int ncarry_x = (b + carry_x + X[j] - '0') / 3;
                int ncarry_y = (b + carry_y + Y[j] - '0') / 3;
                int nneed_less = (need_less ? (b < D[j] - '0' ? 0 : 1) : (b <= D[j] - '0' ? 0 : 1));
                res += solve(j + 1, ncarry_x, ncarry_y, nneed_less);
            }
            return res;
        };
        cout << solve(0, 0, 0, 0) << "\n";
    }
}
