/**
 *    author:  MaGnsi0
 *    created: 01.04.2025 16:55:48
**/
#include <bits/stdc++.h>

using namespace std;

int64_t power(int64_t b, int64_t p, int64_t mod) {
    int64_t res = 1;
    while (p) {
        if (p & 1) { res = res * b % mod; }
        b = b * b % mod; p /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, p, k;
    cin >> n >> p >> k;
    map<int64_t, int64_t> mp;
    for (int i = 0; i < n; ++i) {
        int64_t x; cin >> x;
        mp[x * x % p * x % p]++;
    }
    if (k == 0) {
        cout << mp[0] * (mp[0] - 1) / 2 + mp[0] * (n - mp[0]);
        return 0;
    }
    int64_t ans = 0;
    for (auto [x, c] : mp) {
        if (x == 0) { continue; }
        int64_t y = power(x, p - 2, p) * k % p;  
        if (x == y) {
            ans += c * (c - 1);
        } else {
            ans += c * mp[y];
        }
    }
    cout << ans / 2;
}
