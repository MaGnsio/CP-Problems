/**
 *    author:  MaGnsi0
 *    created: 25.01.2024 21:22:31
**/
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

const int M = 20;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int64_t ans = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) {
            ans += a[i];
        }
    }
    a.resize(unique(a.begin(), a.end()) - a.begin());
    n = (int)a.size();
    int m = (1 << M) - 1;
    vector<vector<int64_t>> dp(1 << M, vector<int64_t>(M + 1, -1));
    for (int i = 0; i < n; ++i) {
        m ^= 1 << (a[i] - 1);
    }
    function<int64_t(int, int)> solve = [&](int mask, int last) {
        if (mask == (1 << M) - 1) { return int64_t(0); }
        int64_t& res = dp[mask][last];
        if (res != -1) { return res; }
        res = 0;
        for (int x = 1; x <= M; ++x) {
            if (mask >> (x - 1) & 1) { continue; }
            res = max(res, solve(mask | (1 << (x - 1)), x) + (last ? __gcd(x, last) : 0));
        }
        return res;
    };
    ans += solve(m, 0);
    cout << ans;
}
