/**
 *    author:  MaGnsi0
 *    created: 27.08.2023 15:15:25
**/
#include <bits/stdc++.h>

using namespace std;

const int M = 100000;

array<int, 10> F(int x) {
    array<int, 10> res;
    for (int i = 0; i < 10; ++i) {
        res[i] = x % 3;
        x /= 3;
    }
    return res;
}

int G(array<int, 10> x) {
    int res = 0, p = 1;
    for (int i = 0; i < 10; ++i) {
        res += p * x[i];
        p *= 3;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int64_t>> dp(n, vector<int64_t>(M, -1));
        function<int64_t(int, int)> solve = [&](int j, int mask) {
            if (j == n) { return int64_t(0); }
            assert(mask < M);
            if (dp[j][mask] != -1) { return dp[j][mask]; }
            dp[j][mask] = solve(j + 1, mask);
            array<int, 10> mask_ = F(mask);
            int64_t x = a[j];
            while (x) {
                mask_[x % 10]++;
                x /= 10;
            }
            bool ok = true;
            for (int i = 0; i < 10; ++i) {
                ok = ok && (mask_[i] < 3);
            }
            if (ok) {
                dp[j][mask] = max(dp[j][mask], solve(j + 1, G(mask_)) + a[j]);
            }
            return dp[j][mask];
        };
        cout << solve(0, 0) << "\n";
    }
}
