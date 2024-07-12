/**
 *    author:  MaGnsi0
 *    created: 11.07.2024 22:18:43
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
        for (int i = 0; i + 1 < n; ++i) {
            if (a[i] != a[i + 1]) { continue; }
            int before = i;
            int after = n - i - 2;
            ok |= (0 <= after - before && after - before <= 2);
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
