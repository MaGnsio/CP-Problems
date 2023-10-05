/**
 *    author:  MaGnsi0
 *    created: 08/09/2021 16:07:21
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;
const int N = 2e5 + 5;

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

vector<int> f = mod_factorials(N, MOD);

template <typename T>
T C_mod(T n, T k, T m) {
    if (k == 0) {
        return 1;
    }
    return (f[n] * pmod_inverse(f[k], m) % m * pmod_inverse(f[n - k], m) % m) % m;
}


int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, maxi = 0;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            maxi = max(maxi, v[i]);
        }
        if (n == 1) {
            cout << (v[0] == 1) << "\n";
            continue;
        }
        int x = 0, y = 0, z = 0;
        for (int i = 0; i < n; ++i) {
            x += (v[i] < maxi - 1);
            y += (v[i] == maxi);
            z += (v[i] == maxi - 1);
        }
        if (x == n - 1) {
            cout << 0 << "\n";
            continue;
        }
        if (y > 1) {
            cout << f[n] << "\n";
            continue;
        }
        int not_nice = 0;
        for (int i = z; i <= z + x; ++i) {
            not_nice = (not_nice % MOD + (f[i] * f[n - i - 1]) % MOD * C_mod(x, i - z, MOD) % MOD) % MOD;
        }
        cout << (((f[n] - not_nice % MOD + MOD) % MOD)) % MOD << "\n";
    }
}
