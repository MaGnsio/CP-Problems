/**
 *    author:  MaGnsi0
 *    created: 26.10.2024 06:34:55
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int64_t power(int64_t b, int64_t p) {
    int64_t res = 1;
    b %= MOD;
    while (p) {
        if (p & 1) { res = res * b % MOD; }
        b = b * b % MOD; p /= 2;
    }
    return res;
}

int64_t C(int64_t n, int64_t k) {
    if (n < k) { return 0; }
    int64_t res = 1;
    for (int64_t x = n; x > k; --x) {
        res *= x % MOD; res %= MOD;
    }
    for (int64_t x = 1; x <= n - k; ++x) {
        res *= power(x, MOD - 2); res %= MOD;
    }
    return res;
}

int64_t stars_and_bars(int64_t n, int64_t k) {
    return C(n + k - 1, n);
}

int64_t F(int64_t k, int64_t low, int64_t high) {
    return (stars_and_bars(high, k + 1) - stars_and_bars(low - 1, k + 1) + MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    bool back_track = false;
    int64_t res = 1;
    vector<bool> done(n, false);
    vector<int> lows(m), highs(m);
    vector<vector<int>> P(m);
    for (int i = 0; i < m; ++i) {
        int64_t low; cin >> low;
        int64_t high; cin >> high;
        int k; cin >> k;
        for (int j = 0; j < k; ++j) {
            int p; cin >> p; p--;
            if (done[p]) { back_track = true; }
            done[p] = true;
            P[i].push_back(p);
        }
        lows[i] = low, highs[i] = high;
        res *= F(k, low, high); res %= MOD;
    }
    for (int i = 0; i < n; ++i) {
        if (!done[i]) {
            cout << "infinity";
            return 0;
        }
    }
    if (back_track) {
        int ans = 0;
        vector<int> a;
        function<void()> solve = [&]() {
            bool good = true;
            for (int i = 0; i < m; ++i) {
                if (P[i].back() >= (int)a.size()) { continue; }
                int64_t sum = 0;
                for (auto p : P[i]) {
                    sum += a[p];
                }
                good = good && lows[i] <= sum && sum <= highs[i];
            }
            if (!good) { return; }
            if ((int)a.size() == n) { ans++; return; }
            for (int x = 0; x <= 100; ++x) {
                a.push_back(x);
                solve();
                a.pop_back();
            }
        };
        solve();
        cout << ans;
        return 0;
    }
    cout << res;
}
