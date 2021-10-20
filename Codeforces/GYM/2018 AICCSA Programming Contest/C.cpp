/**
 *    author:  MaGnsi0
 *    created: 09.10.2021 17:41:04
**/
#include <bits/stdc++.h>

using namespace std;

const long long N = 1e6 + 6, MOD = 1e9 + 7;

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

vector<long long> f = mod_factorials(N, MOD);

template <typename T>
vector<T> inverse_mod_factorials(T n, T m){
    vector<T> inv_f(n);
    for (T i = 0; i < n; ++i) {
        inv_f[i] = pmod_inverse(f[i], m);
    }
    return inv_f;
}

vector<long long> inv_f = inverse_mod_factorials(N, MOD);

template <typename T>
T C_mod(T n, T k, T m) {
    if (k == 0 || n == k) {
        return 1;
    }
    return ((f[n] * inv_f[k] % m * inv_f[n - k] % m) % m - 1 + m) % m;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        long long n, res = 0;
        cin >> n;
        for (long long i = 0; i < n; ++i) {
            long long x;
            cin >> x;
            res = (res + C_mod(n + 1, i + 1, MOD) * x) % MOD;
        }
        cout << res << "\n";
    }
}
