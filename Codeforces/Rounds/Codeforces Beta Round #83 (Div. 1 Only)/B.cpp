/**
 *    author:  MaGnsi0
 *    created: 31.10.2021 18:58:36
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
    long long n, m, h;
    cin >> n >> m >> h;
    vector<long long> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    n--, h--, a[h]--;
    long long x = accumulate(a.begin(), a.end(), 0);
    if (x < n) {
        cout << -1;
        return 0;
    }
    long double res = 0;
    for (long long i = min(n, a[h]); (i + (x - a[h]) >= n) && (i > 0); --i) {
        res += ((1.0 * C<long double>(a[h], i) / C<long double>(x, n)) * C<long double>(x - a[h], n - i));
    }
    cout << fixed << setprecision(6) << res;
}
