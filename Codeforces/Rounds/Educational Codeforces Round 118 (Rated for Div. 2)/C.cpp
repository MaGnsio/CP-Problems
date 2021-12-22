/**
 *    author:  MaGnsi0
 *    created: 01.12.2021 16:24:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        long long h;
        cin >> n >> h;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        long long l = 0, r = h, k = h;
        while (l <= r) {
            long long m = l + (r - l) / 2;
            long long d = 0;
            for (int i = 1; i < n; ++i) {
                d += min(m, a[i] - a[i - 1]);
            }
            d += m;
            if (d >= h) {
                k = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        cout << k << "\n";
    }
}
