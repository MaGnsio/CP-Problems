/**
 *    author:  MaGnsi0
 *    created: 16/07/2021 13:24:47
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;

int biExp(int b, int p) {
    int res = 1;
    while (p) {
        if (p & 1) {
            res = (res * b) % mod;
        }
        b = (b * b) % mod;
        p /= 2;
    }
    return (res % mod);
}

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int x, n;
    cin >> x >> n;
    vector<int> D;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            while (x % i == 0) {
                x /= i;
            }
            D.push_back(i);
        }
    }
    if (x > 1) {
        D.push_back(x);
    }
    int ans = 1;
    for (auto& d : D) {
        int k = 1, p = 0;
        while (k <= n / d) {
            k *= d;
            p += (n / k);
        }
        ans = (ans * biExp(d, p)) % mod;
    }
    cout << ans % mod;
}
