/**
 *    author:  MaGnsi0
 *    created: 31.10.2021 18:27:59
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
    string s, t;
    cin >> s >> t;
    int L = 0, R = 0, Q = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        L += (s[i] == '-') - (t[i] == '-');
        R += (s[i] == '+') - (t[i] == '+');
        Q += (t[i] == '?');
    }
    long double res = (L < 0 || R < 0 ? 0.0 : 1.0 * C(Q, L) / (1LL << Q));
    cout << fixed << setprecision(9) << res;
}
