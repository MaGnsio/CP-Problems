/**
 *    author:  MaGnsi0
 *    created: 10.11.2021 21:21:30
**/
#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MOD = 1e9 + 9;

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

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 2; i <= n; i += 2) {
        int x;
        cout << "? " << 1 << " " << i << endl;
        cin >> x;
        for (int j = 0; j < i - 2; ++j) {
            x *= power<long long>(a[j], MOD - 2, MOD);
            x %= MOD;
        }
        x %= MOD;
        for (int j = 2, k = i - 2; j * j <= x; ++j) {
            while (x % j == 0) {
                a[k++] = j;
                x /= j;
            }
        }
        if (x > 1) {
            a[i - 1] = x;
        }
    }
    if (n & 1) {
        int x;
        cout << "? 1 " << n << endl;
        cin >> x;
        for (int i = 0; i < n - 1; ++i) {
            x *= power<long long>(a[i], MOD - 2, MOD);
            x %= MOD;
        }
        x %= MOD;
        a[n - 1] = x;
    }
    cout << "!";
    for (int i = 0; i < n; ++i) {
        cout << " " << a[i];
    }
    cout << endl;
}
