/**
 *    author:  MaGnsi0
 *    created: 10.08.2025 18:04:09
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        for (int i = n - 2; i >= 0; --i) {
            if (a[i] != b[i]) {
                if ((a[i] ^ a[i + 1]) == b[i] || (a[i] ^ c[i + 1]) == b[i]) {
                    c[i] = a[i]; a[i] = b[i];
                }
            }
        }
        cout << (a == b ? "YES" : "NO") << "\n";
    }
}
