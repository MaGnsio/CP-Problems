/**
 *    author:  MaGnsi0
 *    created: 04.11.2021 17:20:49
**/
#include <bits/stdc++.h>

using namespace std;

const long long N = 1e6 + 6, MOD = 998244353;

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
    vector<vector<int>> a(n);
    vector<int> cnt(N, 0);
    for (int i = 0; i < n; ++i) {
        int k_i;
        cin >> k_i;
        a[i].resize(k_i);
        for (int j = 0; j < k_i; ++j) {
            cin >> a[i][j];
            cnt[a[i][j]]++;
        }
    }
    long long p = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (int)a[i].size(); ++j) {
            long long p1 = power<long long>(n, MOD - 2, MOD);
            long long p2 = power<long long>((int)a[i].size(), MOD - 2, MOD);
            long long p3 = cnt[a[i][j]] * power<long long>(n, MOD - 2, MOD);
            p += (((p1 % MOD) * (p2 % MOD) % MOD) * (p3 % MOD)) % MOD;
            p %= MOD;
        }
    }
    cout << p;
}
