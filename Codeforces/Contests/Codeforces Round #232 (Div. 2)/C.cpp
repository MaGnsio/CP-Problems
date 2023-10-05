/**
 *    author:  MaGnsi0
 *    created: 29.10.2021 15:33:58
**/
#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

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

vector<long long> f = mod_factorials(1000000LL, MOD);

template <typename T>
vector<T> inverse_mod_factorials(T n, T m){
    vector<T> inv_f(n);
    for (T i = 0; i < n; ++i) {
        inv_f[i] = pmod_inverse(f[i], m);
    }
    return inv_f;
}

vector<long long> inv_f = inverse_mod_factorials(1000000LL, MOD);

template <typename T>
T C_mod(T n, T k, T m) {
    if (k == 0) {
        return 1;
    }
    return (f[n] * inv_f[k] % m * inv_f[n - k] % m) % m;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    map<int, long long> mp;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        for (int i = 2; i * i <= x; ++i) {
            while (x % i == 0) {
                x /= i;
                mp[i]++;
            }
        }
        if (x > 1) {
            mp[x]++;
        }
    }
    long long res = 1;
    for (auto& [x, y] : mp) {
        res *= C_mod<long long>(y + n - 1, n - 1, MOD);
        res %= MOD;
    }
    cout << res;
}
