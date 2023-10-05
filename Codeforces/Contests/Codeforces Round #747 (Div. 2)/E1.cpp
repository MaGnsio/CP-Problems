/**
 *    author:  MaGnsi0
 *    created: 08.10.2021 18:26:02
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
    int n;
    cin >> n;
    long long res = 6;
    for (int i = 2; i <= n; ++i) {
        res = (res * power<long long>(4, (1LL << (i - 1)) , MOD)) % MOD;
    }
    cout << res;
}
