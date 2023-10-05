/**
 *    author:  MaGnsi0
 *    created: 07.10.2022 17:07:47
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 1e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    function<int64_t(int64_t)> F = [](int64_t x) {
        return (x ? int64_t(3 * x) : int64_t(0));
    };
    function<int64_t(int64_t)> solve = [&](int64_t n) {
        if (n == 0) {
            return int64_t(0);
        }
        int64_t l = 1, r = N, x;
        while (l <= r) {
            int64_t m = l + (r - l) / 2;
            if (m * m <= n) {
                x = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        int64_t ans = F(x - 1) + n / x - (x * x - 1) / x;
        return ans;
    };
    int T;
    cin >> T;
    while (T--) {
        int64_t l, r;
        cin >> l >> r;
        cout << solve(r) - solve(l - 1) << "\n";
    }
}
