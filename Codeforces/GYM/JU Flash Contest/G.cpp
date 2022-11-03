/**
 *    author:  MaGnsi0
 *    created: 27.06.2022 19:40:12
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7, N = 2e5 + 5;

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
    return (f[n] * inv_f[k] % m * inv_f[n - k] % m) % m;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, k;
        cin >> n >> k;
        if (k & 1) {
            cout << 0 << "\n";
            continue;
        }
        int64_t ans = 0, rem = n % k;
        for (int i = 0; i <= k / 2; ++i) {
            int64_t x = i, y = k / 2 - i;
            int64_t z = C_mod(rem, x, MOD);
            z *= power<int64_t>(2, x * (n / k + 1), MOD);
            z %= MOD;
            z *= C_mod(k - rem, y, MOD);
            z %= MOD;
            z *= power<int64_t>(2, y * (n / k), MOD);
            z %= MOD;
            ans += z;
            ans %= MOD;
        }
        cout << ans << "\n";
    }
}
