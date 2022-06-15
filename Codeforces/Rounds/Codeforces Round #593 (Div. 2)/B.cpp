/**
 *    author:  MaGnsi0
 *    created: 10.03.2022 12:13:08
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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n, m;
    cin >> n >> m;
    long long ans = power((power<long long>(2, m, MOD) - 1 + MOD) % MOD, n, MOD) % MOD;
    cout << ans;
}
