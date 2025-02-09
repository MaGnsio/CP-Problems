/**
 *    author:  MaGnsi0
 *    created: 09.02.2025 16:40:44
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        sort(b.begin(), b.end());
        a[0] = min(a[0], b[0] - a[0]);
        bool ok = true;
        for (int i = 1; i < n; ++i) {
            auto it = lower_bound(b.begin(), b.end(), a[i] + a[i - 1]);
            if (it != b.end()) {
                if (a[i] >= a[i - 1]) {
                    a[i] = min(a[i], *it - a[i]);
                } else {
                    a[i] = *it - a[i];
                }
            } else if (a[i] < a[i - 1]) {
                ok = false; break;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}

