/**
 *    author:  MaGnsi0
 *    created: 26.01.2025 22:23:08
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
        for (int i = 1; i < n; ++i) {
            int x = min(a[i], a[i - 1]);
            a[i] -= x; a[i - 1] -= x;
        }
        bool ok = true;
        for (int i = 1; i < n; ++i) {
            ok = ok && a[i] >= a[i - 1];
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
