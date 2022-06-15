/**
 *    author:  MaGnsi0
 *    created: 15.03.2022 22:28:47
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 6, MOD = 1e9 + 7;

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

template <typename T>
T P_mod(T n, T k, T m) {
    return (f[n] * inv_f[n - k]) % m;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> lpf(N, 0);
    for (int i = 2; i < N; ++i) {
        if (lpf[i] == 0) {
            lpf[i] = i;
            for (int j = 2 * i; j < N; j += i) {
                lpf[j] = (lpf[j] ? min(i, lpf[j]) : i);
            }
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        map<int, int> mp;
        while (x != 1) {
            mp[lpf[x]]++;
            x /= lpf[x];
        }
        long long ans = 1;
        for (auto& [a, b] : mp) {
            ans *= C_mod<long long>(y + b - 1, b, MOD);
            ans %= MOD;
        }
        ans *= power<long long>(2, y - 1, MOD);
        ans %= MOD;
        cout << ans << "\n";
    }
}
