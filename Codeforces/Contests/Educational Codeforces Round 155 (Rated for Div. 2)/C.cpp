/**
 *    author:  MaGnsi0
 *    created: 24.09.2023 19:55:04
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 2e5 + 5, MOD = 998244353;

int64_t power(int64_t b, int64_t p) {
    int64_t res = 1;
    while (p) {
        if (p & 1) { res = res * b % MOD; }
        b = b * b % MOD;
        p /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int64_t> F(N, 1), F_(N, 1);
    for (int i = 1; i < N; ++i) {
        F[i] = F[i - 1] * i % MOD;
        F_[i] = power(F[i], MOD - 2);
    }
    function<int64_t(int, int)> C = [&](int n, int k) {
        return F[n] * F_[k] % MOD * F_[n - k] % MOD;
    };
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = (int)s.size();
        vector<int> a(1, 1);
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) {
                a.back()++;
            } else {
                a.push_back(1);
            }
        }
        int ans1 = n - (int)a.size();
        int64_t ans2 = 1, X = 0;
        for (int x : a) {
            ans2 *= C(x, x - 1);
            ans2 %= MOD;
            X += x - 1;
        }
        ans2 = ans2 * F[X] % MOD;
        cout << ans1 << " " << ans2 << "\n";
    }
}
