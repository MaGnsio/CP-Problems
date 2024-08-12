/**
 *    author:  MaGnsi0
 *    created: 12.08.2024 20:49:13
**/
#include <bits/stdc++.h>

using namespace std;

int F(long long x, long long y = 2) {
    int res = 1;
    while (x) {
        if (x & 1) { res = res * y % 10; }
        x /= 2;
        y = y * y % 10;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        long long n; cin >> n;
        long long m; cin >> m;
        long long k; cin >> k;
        if (k + 1 == m) {
            cout << (k <= n ? 0 : F(n)) << "\n";
        } else {
            if (n >= m) {
                long long x = (m - k);
                n -= (n - m) / x * x + x;
            }
            cout << F(n) << "\n";
        }
    }
}
