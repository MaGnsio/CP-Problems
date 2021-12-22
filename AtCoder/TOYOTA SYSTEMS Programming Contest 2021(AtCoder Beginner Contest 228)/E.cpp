/**
 *    author:  MaGnsi0
 *    created: 20.11.2021 14:35:06
**/
#include <bits/stdc++.h>

using namespace std;

const long long MOD = 998244353;

template <typename T>
T product(T x, T y, T m) { 
    if (x < y) {
        return product(y, x, m);
    }
    if (y == 0) {
        return 0;
    }
    T res = 0;
    while (y) {
        if (y & 1) {
            res = ((res % m) + (x % m)) % m;
        }
        x = ((x % m) + (x % m)) % m;
        y >>= 1LL;
    }
    return (res + m) % m;
}

template <typename T>
T power(T b, T p, T m) {
    T res = 1;
    while (p) {
        if (p & 1) {
            res = product(res % m, b % m, m) % m;
        }
        b = product(b % m, b % m, m) % m;
        p >>= 1LL;
    }
    return (res + m) % m;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n, k, m;
    cin >> n >> k >> m;
    long long x = power(k, n, MOD - 1);
    long long res = power(m, x, MOD);
    if (m % MOD == 0) {
        cout << 0;
        return 0;
    }
    cout << (res + MOD) % MOD;
}
