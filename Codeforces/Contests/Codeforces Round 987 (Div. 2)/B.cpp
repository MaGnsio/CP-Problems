/**
 *    author:  MaGnsi0
 *    created: 15.11.2024 14:40:00
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
        int maxe = a[0];
        bool ok = true;
        for (int i = 1; i < n; ++i) {
            ok = ok && (maxe <= a[i] + 1);
            maxe = max(maxe, a[i]);
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
