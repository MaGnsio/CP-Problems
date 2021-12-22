/**
 *    author:  MaGnsi0
 *    created: 29.10.2021 16:29:08
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        long long n, k;
        cin >> n >> k;
        long long p = (1LL << 61);
        while (p > k) {
            p /= 2;
        }
        p *= 2;
        if (p >= n) {
            long long res = log2(n);
            cout << res + ((1LL << res) < n) << "\n";
        } else {
            long long res = log2(p);
            n -= p;
            res += (n + k - 1) / k;
            cout << res << "\n";
        }
    }
}
