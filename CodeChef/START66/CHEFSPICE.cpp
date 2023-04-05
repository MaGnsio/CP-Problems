/**
 *    author:  MaGnsi0
 *    created: 23.11.2022 17:47:24
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, m, k;
        cin >> n >> m >> k;
        if (k > n * m) {
            cout << "NO\n";
            continue;
        }
        if (k % n == 0 || k % m == 0) {
            cout << "YES\n";
            continue;
        }
        if (k < n && k < m) {
            cout << "NO\n";
            continue;
        }
        bool ok = false;
        for (int64_t i = 1; i * i <= k; ++i) {
            int64_t rem = k - i * n;
            if (rem < 0) {
                continue;
            }
            if (rem == 0) {
                ok = true;
                break;
            }
            if (m <= i) {
                continue;
            }
            if (rem % (m - i) == 0) {
                ok = true;
                break;
            }
        }
        for (int64_t i = 1; i * i <= k; ++i) {
            int64_t rem = k - i * m;
            if (rem < 0) {
                continue;
            }
            if (rem == 0) {
                ok = true;
                break;
            }
            if (n <= i) {
                continue;
            }
            if (rem % (n - i) == 0) {
                ok = true;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
