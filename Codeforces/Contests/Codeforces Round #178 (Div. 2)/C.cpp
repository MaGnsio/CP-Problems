/**
 *    author:  MaGnsi0
 *    created: 16.03.2022 14:32:35
**/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

template <typename T>
T power(T b, T p, T m) {
    if (!b || !p) {
        return 1;
    }
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
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<long long> F(n, 1);
    for (int i = 1; i < n; ++i) {
        F[i] = (F[i - 1] * i) % MOD;
    }
    long long ans = F[n - m];
    ans %= MOD;
    ans *= power<long long>(F[a[0] - 1], MOD - 2, MOD);
    ans %= MOD;
    ans *= power<long long>(F[n - a[m - 1]], MOD - 2, MOD);
    ans %= MOD;
    for (int i = 1; i < m; ++i) {
        ans *= power<long long>(F[a[i] - a[i - 1] - 1], MOD - 2, MOD);
        ans %= MOD;
        ans *= power<long long>(2, max(0, a[i] - a[i - 1] - 2), MOD); 
        ans %= MOD;
    }
    cout << ans;
}
