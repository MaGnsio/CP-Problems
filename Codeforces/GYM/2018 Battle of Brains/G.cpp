/**
 *    author:  MaGnsi0
 *    created: 17/08/2021 20:06:05
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

template <typename T>
T modInv(T n, T m) {
    return biExp(n, m - 2, m);
}

const int m = 1e9 + 7;
const long long modInv2 = modInv<long long>(2, m);


int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        string s;
        cin >> n >> s;
        vector<long long> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            dp[i] = (dp[i - 1] + modInv2 * i * (i + 1)) % m;
        }
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            long long k = (dp[n] - (dp[i] + dp[n - i - 1]) + m) % m;
            res = (res + 1LL * s[i] * k) % m;
        }
        cout << "Case " << t << ": " << res << "\n";
    }
}
