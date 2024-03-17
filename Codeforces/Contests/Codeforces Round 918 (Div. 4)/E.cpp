/**
 *    author:  MaGnsi0
 *    created: 28.12.2023 18:27:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (i & 1) { a[i] *= -1; }
        }
        for (int i = 1; i < n; ++i) {
            a[i] += a[i - 1];
        }
        bool ok = false;
        set<int64_t> sums;
        sums.insert(0);
        for (int i = 0; i < n; ++i) {
            ok |= sums.count(a[i]);
            sums.insert(a[i]);
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
