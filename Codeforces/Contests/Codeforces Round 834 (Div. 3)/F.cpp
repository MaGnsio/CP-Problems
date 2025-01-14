/**
 *    author:  MaGnsi0
 *    created: 14.01.2025 19:32:19
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int p; cin >> p;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        reverse(a.begin(), a.end());
        set<int> s(a.begin(), a.end());
        int l = 0, r = p - 1;
        while (s.count(l)) { l++; }
        while (s.count(r)) { r--; }
        if (l > r) {
            cout << 0 << "\n";
            continue;
        }
        assert(a[0] != l && a[0] != r);
        if (l < a[0] && a[0] < r) {
            int ans = p - a[0];
            if (n == 1) { s.insert(1); }
            for (int i = 1; i < n; ++i) {
                if (a[i] != p - 1) {
                    s.insert(a[i] + 1);
                    break;
                }
                if (i == n - 1) { s.insert(1); }
                s.insert(0);
            }
            l = a[0];
            while (s.count(l)) { l--; }
            if (l != -1) { ans += l; }
            cout << ans << "\n";
        } else if (a[0] < l) {
            cout << r - a[0] << "\n";
        } else if (r < a[0]) {
            int ans = p - a[0];
            if (n == 1) { s.insert(1); }
            for (int i = 1; i < n; ++i) {
                if (a[i] != p - 1) {
                    s.insert(a[i] + 1);
                    break;
                }
                if (i == n - 1) { s.insert(1); }
                s.insert(0);
            }
            while (s.count(r)) { r--; }
            if (r != -1) { ans += r; }
            cout << ans << "\n";
        }
    }
}
