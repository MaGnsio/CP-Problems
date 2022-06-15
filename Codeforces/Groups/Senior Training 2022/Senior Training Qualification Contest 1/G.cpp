/**
 *    author:  MaGnsi0
 *    created: 11.03.2022 21:07:07
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, MOD = 1e9 + 7;

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
    freopen("permutation.in", "r", stdin);
    vector<long long> dp(N, -1);
    function<long long(int)> solve = [&](int i) {
        if (i == 0) {
            return 1LL;
        }
        if (i == 1) {
            return 0LL;
        }
        if (i == 2) {
            return 1LL;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        dp[i] = (i - 1) * (solve(i - 1) + solve(i - 2)) % MOD;
        return dp[i] % MOD;
    };
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        cout << C_mod(n, k, MOD) * solve(n - k) % MOD << "\n";
    }
}
