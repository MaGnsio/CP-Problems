/**
 *    author:  MaGnsi0
 *    created: 17.05.2023 17:49:53
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 1e5 + 5, MOD = 1e9 + 7;

int64_t power(int64_t b, int64_t p) {
    int64_t ans = 1;
    while (p) {
        if (p & 1) { ans = ans * b % MOD; }
        b = b * b % MOD;
        p /= 2;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int64_t> F(N, 1), inv_F(N, 1), P2(N, 1);
    for (int i = 1; i < N; ++i) {
        F[i] = i * F[i - 1] % MOD;
        inv_F[i] = power(F[i], MOD - 2);
        P2[i] = 2 * P2[i - 1] % MOD;
    }
    function<int64_t(int, int)> C = [&](int n, int k) {
        if (k > n) { return int64_t(0); }
        return F[n] * inv_F[k] % MOD * inv_F[n - k] % MOD;
    };
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int64_t ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += C(i, a[i] - 1) * P2[n - i - 1] % MOD;
            ans %= MOD;
        }
        cout << ans << "\n";
    }
}
