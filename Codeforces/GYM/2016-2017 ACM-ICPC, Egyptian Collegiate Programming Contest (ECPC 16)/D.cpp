/**
 *    author:  MaGnsi0
 *    created: 08.03.2022 16:02:31
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
    freopen("popcorn.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << C<long long>(n, m) << "\n"; 
    }
}
