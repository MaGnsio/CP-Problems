/**
 *    author:  MaGnsi0
 *    created: 05.01.2022 21:10:20
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
    int x = n * (n + 1) / 2;
    if (x & 1) {
        cout << 0;
        return 0;
    }
    vector<long long> dp((x / 2) + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = x / 2; j >= i; --j) {
            dp[j] += dp[j - i];
            dp[j] %= MOD;
        }
    }
    cout << dp[x / 2] * power(2LL, MOD - 2, MOD) % MOD;
}
