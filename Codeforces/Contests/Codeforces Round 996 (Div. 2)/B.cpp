/**
 *    author:  MaGnsi0
 *    created: 12.01.2025 17:25:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        for (int i = 0; i < n; ++i) {
            c[i] = a[i] - b[i];
        }
        sort(c.begin(), c.end());
        if (c[1] < 0) {
            cout << "NO\n";
        } else if (c[0] > 0) {
            cout << "YES\n";
        } else {
            bool ok = true;
            for (int i = 1; i < n; ++i) {
                ok = ok && c[i] >= abs(c[0]);
            }
            cout << (ok ? "YES" : "NO") << "\n";
        }
    }
}
