/**
 *    author:  MaGnsi0
 *    created: 25.11.2024 22:02:15
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 19, F2 = 55, F3 = 37, F5 = 19, F7 = 19, OO = 2e18;

int64_t dp[F2][F3][F5][F7], P10[N];

int64_t S(int64_t x) {
    int64_t s = 0;
    while (x) { x /= 10; s++; }
    return s;
}

int64_t solve(int f2, int f3, int f5, int f7) {
    if (!f2 && !f3 && !f5 && !f7) { return 0; }
    int64_t& res = dp[f2][f3][f5][f7];
    if (res != -1) { return res; }
    res = OO;
    for (int64_t d = 1; d < 10; ++d) {
        int x = d, f2_ = f2, f3_ = f3, f5_ = f5, f7_ = f7;
        while (x % 2 == 0) { x /= 2, f2_--; }
        while (x % 3 == 0) { x /= 3, f3_--; }
        while (x % 5 == 0) { x /= 5, f5_--; }
        while (x % 7 == 0) { x /= 7, f7_--; }
        if (f2_ < 0 || f3_ < 0 || f5_ < 0 || f7_ < 0) { continue; }
        int64_t n = solve(f2_, f3_, f5_, f7_);
        int64_t m = S(n);
        if (m + 1 >= N) { continue; }
        res = min(res, P10[m] * d + n);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    P10[0] = 1;
    for (int i = 1; i < N; ++i) {
        P10[i] = P10[i - 1] * 10;
    }
    vector<int64_t> MD(1, 10);
    for (int f2 = 0; f2 < F2; ++f2) {
        for (int f3 = 0; f3 < F3; ++f3) {
            for (int f5 = 0; f5 < F5; ++f5) {
                for (int f7 = 0; f7 < F7; ++f7) {
                    MD.push_back(solve(f2, f3, f5, f7));
                }
            }
        }
    }
    sort(MD.begin(), MD.end());
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        int64_t ans = upper_bound(MD.begin(), MD.end(), n) - MD.begin();
        cout << ans << "\n";
    }
}
