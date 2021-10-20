/**
 *    author:  MaGnsi0
 *    created: 18/08/2021 01:48:38
**/
#include <bits/stdc++.h>
using namespace std;


template <typename T>
T biExp(T b, T p, T m) {
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
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, p, k;
    cin >> n >> p >> k;
    vector<long long> v(n);
    for (auto& x : v) {
        cin >> x;
    }
    map<long long, int> mp;
    for (auto& x : v) {
        mp[(((biExp<long long>(x, 4, p)) % p) - ((k % p) * (x % p) % p) + p) % p]++;
    }
    long long res = 0;
    for (auto& [x, y] : mp) {
        res += y * (y - 1) / 2;
    }
    cout << res;
}
