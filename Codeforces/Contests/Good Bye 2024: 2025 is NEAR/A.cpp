/**
 *    author:  MaGnsi0
 *    created: 29.12.2024 23:12:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        bool ok = false;
        for (int i = 1; i < n; ++i) {
            ok |= 2 * min(a[i - 1], a[i]) > max(a[i], a[i - 1]);
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
