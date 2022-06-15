/**
 *    author:  MaGnsi0
 *    created: 17.03.2022 14:03:12
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, MOD = 998244353;

template <typename T>
T power(T b, T p, T m) {
    if (p < 0) {
        return 0;
    }
    if (!b || !p) {
        return 1;
    }
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

vector<long long> f = mod_factorials<long long>(N, MOD);

template <typename T>
vector<T> inverse_mod_factorials(T n, T m){
    vector<T> inv_f(n);
    for (T i = 0; i < n; ++i) {
        inv_f[i] = pmod_inverse(f[i], m);
    }
    return inv_f;
}

vector<long long> inv_f = inverse_mod_factorials<long long>(N, MOD);

template <typename T>
T C_mod(T n, T k, T m) {
    if (k == 0) {
        return 1;
    }
    return (f[n] * inv_f[k] % m * inv_f[n - k] % m) % m;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    long long ans = ((1LL * C_mod<long long>(m, n - 1, MOD) * (n - 2) % MOD) * power<long long>(2, n - 3, MOD)) % MOD;
    cout << ans;
}
