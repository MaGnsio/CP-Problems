/**
 *    author:  MaGnsi0
 *    created: 18.10.2025 20:44:13
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    function<vector<pair<int64_t, int64_t>>(int64_t x)> factorize = [&](int64_t x) {
        map<int64_t, int64_t> mp;
        for (int64_t i = 2; i * i <= x; ++i) {
            while (x % i == 0) { mp[i]++; x /= i; }
        }
        if (x > 1) { mp[x] = 1; }
        vector<pair<int64_t, int64_t>> res;
        for (auto [x, y] : mp) {
            res.emplace_back(x, y);
        }
        return res;
    };
    function<int64_t(int64_t, int64_t)> power = [&](int64_t b, int64_t p) {
        int64_t res = 1;
        b %= MOD, p %= MOD;
        while (p) {
            if (p & 1) { res = res * b % MOD; }
            p /= 2; b = b * b % MOD;
        }
        return res;
    };
    function<int64_t(int64_t, int64_t)> C = [&](int64_t n, int64_t c) {
        if (c > n) { return int64_t(0); }
        if (n == 0 || c == 0) { return int64_t(1); }
        int64_t res = 1;
        for (int64_t x = n; x > n - c; --x) {
            res *= x % MOD; res %= MOD;
        }
        for (int64_t x = 1; x <= c; ++x) {
            res *= power(x, MOD - 2) % MOD; res %= MOD;
        }
        return res;
    };
    function<int64_t(int64_t, int64_t)> stars_and_bars = [&](int64_t stars, int64_t bars) {
        return C(stars + bars - 1, stars);
    };
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        int64_t N; cin >> N;
        int64_t A; cin >> A;
        int64_t B; cin >> B;
        auto factorsB = factorize(B);
        int m = (int)factorsB.size();
        vector<map<int64_t, int64_t>> dp(m);
        function<int64_t(int, int64_t)> solve = [&](int j, int64_t v) {
            if (j == m) { return int64_t(1); }
            if (dp[j].count(v)) { return dp[j][v]; }
            int64_t nv = 1; dp[j][v] = 0;
            auto [x, y] = factorsB[j];
            for (int i = 0; i <= y; ++i) {
                if (v * nv > A) { break; }
                dp[j][v] += stars_and_bars(i, N) * stars_and_bars(y - i, N) % MOD * solve(j + 1, v * nv) % MOD; dp[j][v] %= MOD;
                nv *= x;
            }
            return dp[j][v];
        };
        int64_t ans = solve(0, 1);
        cout << ans << "\n";
    }
}
