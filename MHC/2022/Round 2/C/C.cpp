/**
 *    author:  MaGnsi0
 *    created: 24.09.2022 19:56:14
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 5e6, MOD = 1e9 + 7;

template <typename T>
T power(T b, T p, T m) {
    T res = 1;
    while (p) {
        if (p & 1) {
            res = ((res % m) * (b % m)) % m;
        }
        b = ((b % m) * (b % m)) % m;
        p >>= 1;
    }
    return res;
}

template <typename T>
T pmod_inverse(T n, T m) {
    return power(n, m - 2, m);
}

template <typename T>
vector<T> mod_factorials(T n, T m){
    vector<T> f(n);
    f[0] = 1;
    for (T i = 1; i < n; ++i) {
        f[i] = (f[i - 1] * i) % m;
    }
    return f;
}

vector<int64_t> f = mod_factorials(N, MOD);

template <typename T>
vector<T> inverse_mod_factorials(T n, T m){
    vector<T> inv_f(n);
    for (T i = 0; i < n; ++i) {
        inv_f[i] = pmod_inverse(f[i], m);
    }
    return inv_f;
}

vector<int64_t> inv_f = inverse_mod_factorials(N, MOD);

template <typename T>
T C_mod(T n, T k, T m) {
    if (k == 0) {
        return 1;
    }
    if (k > n) {
        return 0;
    }
    return (f[n] * inv_f[k] % m * inv_f[n - k] % m) % m;
}

template <typename T>
T P_mod(T n, T k, T m) {
    return (f[n] * inv_f[n - k]) % m;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, k;
        cin >> n >> k;
        vector<int64_t> c(n), w(n);
        for (int i = 0; i < n; ++i) {
            cin >> c[i] >> w[i];
        }
        int64_t cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for (int i = 1; i < n; ++i) {
            cnt1 += (w[i] < w[0]) * c[i];
            cnt2 += (w[i] == w[0]) * c[i];
            cnt3 += (w[i] > w[0]) * c[i];
        }
        int64_t ans = C_mod<int64_t>(c[0] + cnt1 + cnt2, k + 1, MOD);
        ans %= MOD;
        ans -= C_mod<int64_t>(cnt1, k + 1, MOD);
        ans += MOD;
        ans %= MOD;
        ans *= pmod_inverse(C_mod<int64_t>(c[0] + cnt1 + cnt2 + cnt3, k + 1, MOD), MOD);
        ans %= MOD;
        ans *= c[0];
        ans %= MOD;
        ans *= pmod_inverse(c[0] + cnt2, MOD);
        ans %= MOD;
        cout << "Case #" << t << ": " << ans << "\n";
    }
}
