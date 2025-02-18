/**
 *    author:  MaGnsi0
 *    created: 18.02.2025 16:36:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> b(n);
        for (int i = 1; i < n - 1; ++i) {
            cin >> b[i];
        }
        vector<int> a(n); a[0] = 1;
        for (int i = 1, x = 2; i < n - 1; ++i) {
            if (b[i] == 1) {
                a[i] = a[i + 1] = a[i - 1];
            } else {
                a[i + 1] = x++;
            }
        }
        bool ok = true;
        for (int i = 1; i < n - 1; ++i) {
            if (b[i] == 1) {
                ok = ok && (a[i] == a[i + 1] && a[i] == a[i - 1]);
            } else {
                ok = ok && (a[i] != a[i + 1] || a[i] != a[i - 1]);
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
