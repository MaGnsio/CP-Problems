/**
 *    author:  MaGnsi0
 *    created: 28.05.2023 21:35:45
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 3e5 + 5, MOD = 998244353;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int64_t power(int64_t b, int64_t p) {
    int64_t ans = 1;
    while (p) {
        if (p & 1) { ans = ans * b % MOD; }
        b = b * b % MOD;
        p /= 2;
    }
    return ans;
}

int64_t random() {
    return uniform_int_distribution<int64_t>(1e9, 1e18)(rng);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int64_t> F(N, 1), F_(N, 1);
    for (int i = 1; i < N; ++i) {
        F[i] = F[i - 1] * i % MOD;
        F_[i] = power(F[i], MOD - 2);
    }
    function<int64_t(int)> C = [&](int n) {
        if (n & 1) { return int64_t(0); }
        return F[n] * F_[n / 2] % MOD * F_[n / 2 + 1] % MOD;
    };
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int64_t> a(n + 1, 0);
        function<void(int, int)> add = [&](int l, int r) {
            int64_t x = random();
            a[l] ^= x, a[r + 1] ^= x;
        };
        for (int i = 0; i < k; ++i) {
            int l, r;
            cin >> l >> r;
            add(l - 1, r - 1);
        }
        add(0, n - 1);
        for (int i = 1; i < n; ++i) {
            a[i] ^= a[i - 1];
        }
        map<int64_t, int> mp;
        for (int i = 0; i < n; ++i) {
            mp[a[i]]++;
        }
        int64_t ans = 1;
        for (auto [x, y] : mp) {
            ans *= C(y);
            ans %= MOD;
        }
        cout << ans << "\n";
    }
}
