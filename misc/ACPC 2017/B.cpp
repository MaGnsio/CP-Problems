/**
 *    author:  MaGnsi0
 *    created: 29.07.2023 17:23:00
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 63;

int64_t n, dp[N][2][2][2];

int64_t solve(int bit, int last, int tie, int not_zero) {
    if (bit < 0) { return not_zero; }
    int64_t& ans = dp[bit][last][tie][not_zero];
    if (ans != -1) { return ans; }
    ans = solve(bit - 1, 0, tie || (n >> bit & 1), not_zero);
    if (last) { return ans; }
    if (n >> bit & 1) {
        ans += solve(bit - 1, 1, tie, 1);
    } else if (tie) {
        ans += solve(bit - 1, 1, tie, 1);
    }
    return ans;
}

int64_t F(int64_t x) {
    n = x;
    if (x == 0) { return 0; }
    memset(dp, -1, sizeof dp);
    return solve(N - 1, 0, 0, 0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t L, R;
        cin >> L >> R;
        cout << (R - L + 1) - (F(R) - F(L - 1)) << "\n";
    }
}
