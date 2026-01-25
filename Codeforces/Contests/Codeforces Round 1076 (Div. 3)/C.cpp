/**
 *    author:  MaGnsi0
 *    created: 25.01.2026 16:43:09
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int Q; cin >> Q;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        for (int i = n - 1; i >= 0; --i) {
            a[i] = max({a[i], (i + 1 < n ? a[i + 1] : 0), b[i]});
        }
        for (int i = 1; i < n; ++i) {
            a[i] += a[i - 1];
        }
        while (Q--) {
            int l; cin >> l; l--;
            int r; cin >> r; r--;
            cout << a[r] - (l ? a[l - 1] : 0) << " ";
        }
        cout << "\n";
    }
}
