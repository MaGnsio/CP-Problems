/**
 *    author:  MaGnsi0
 *    created: 22.11.2024 17:41:59
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
        sort(a.begin(), a.end());
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            if (i && a[i] == a[i - 1]) { continue; }
            ok |= (n - i) & 1;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
