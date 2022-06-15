/**
 *    author:  MaGnsi0
 *    created: 09.03.2022 21:03:56
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
T C(T n, T k) {
    if (k > n - k) {
        k = n - k;
    }
    T res = 1;
    for (T i = k + 1; i <= n; ++i) {
        T d = (i - k);
        T q = i / d;
        T r = i - q * d;
        res = res * q + res * r / d;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n, m, t;
    cin >> n >> m >> t;
    long long ans = 0;
    for (int i = 4; i < t; ++i) {
        if (i > n || t - i > m) {
            continue;
        }
        ans += C<long long>(n, i) * C<long long>(m, t - i);
    }
    cout << ans;
}
