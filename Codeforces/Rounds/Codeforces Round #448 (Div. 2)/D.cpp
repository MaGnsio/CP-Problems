/**
 *    author:  MaGnsi0
 *    created: 04.01.2023 03:05:59
**/
#include <bits/stdc++.h>

using namespace std;

int64_t MOD = 1e9 + 7;

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
    string s, t;
    cin >> s >> t;
    int n = (int)s.size();
    vector<int64_t> F(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        F[i] = F[i - 1] * i;
        F[i] %= MOD;
    }
    vector<int64_t> invF(n + 1);
    for (int i = 0; i <= n; ++i) {
        invF[i] = power(F[i], MOD - 2);
    }
    vector<int> f(26, 0);
    for (int i = 0; i < n; ++i) {
        f[s[i] - 'a']++;
    }
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        int64_t all = F[n - i - 1];
        for (int j = 0; j < 26; ++j) {
            all *= invF[f[j]];
            all %= MOD;
        }
        for (int j = s[i] - 'a' + 1; j < 26; ++j) {
            if (f[j] == 0) { continue; }
            ans += all * F[f[j]] % MOD * invF[f[j] - 1] % MOD;
            ans %= MOD;
        }
        f[s[i] - 'a']--;
    }
    for (int i = 0; i < n; ++i) {
        f[s[i] - 'a']++;
    }
    for (int i = 0; i < n; ++i) {
        int64_t all = F[n - i - 1];
        for (int j = 0; j < 26; ++j) {
            all *= invF[f[j]];
            all %= MOD;
        }
        for (int j = t[i] - 'a' + 1; j < 26; ++j) {
            if (f[j] == 0) { continue; }
            ans -= all * F[f[j]] % MOD * invF[f[j] - 1] % MOD;
            ans += MOD;
            ans %= MOD;
        }
        if (f[t[i] - 'a'] == 0) { break; }
        f[t[i] - 'a']--;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    ans -= s == t;
    ans += MOD;
    ans %= MOD;
    cout << ans;
}
