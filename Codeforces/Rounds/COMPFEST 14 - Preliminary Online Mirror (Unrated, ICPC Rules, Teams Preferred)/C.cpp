/**
 *    author:  MaGnsi0
 *    created: 04.09.2022 16:40:18
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 5e5 + 5, MOD = 998244353;

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
    if (k > n) {
        return 0;
    }
    if (k == 0) {
        return 1;
    }
    if (n <= 0 || k < 0) {
        return 0;
    }
    return (f[n] * inv_f[k] % m * inv_f[n - k] % m) % m;
}

template <typename T>
T P_mod(T n, T k, T m) {
    if (k > n) {
        return 0;
    }
    if (n <= 0 || k < 0) {
        return 0;
    }
    return (f[n] * inv_f[n - k]) % m;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        a[i] += a[i - 1];
    }
    int64_t P = 0, C = a[n - 1];
    if (C & 1) {
        cout << power<int64_t>(m, n, MOD);
        return 0;
    }
    set<int64_t> s(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        P += s.count(a[i] + C / 2);
    }
    int64_t ans = 0;
    for (int i = 0; i <= P; ++i) {
        if (m - i < 2 && i != P) {
            continue;
        }
        int64_t val = C_mod<int64_t>(P, i, MOD);
        val %= MOD;
        val *= P_mod<int64_t>(m, i, MOD);
        val %= MOD;
        val *= power<int64_t>(int64_t(m - i) * (m - i - 1), P - i, MOD);
        val %= MOD;
        val *= power<int64_t>(m - i, n - 2 * P, MOD);
        val %= MOD;
        ans += val;
        ans %= MOD;
    }
    cout << ans;
}
