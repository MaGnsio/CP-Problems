/**
 *    author:  MaGnsi0
 *    created: 16.01.2025 00:37:20
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
            for (int _ = 1; _ < a[i]; ++_) {
                int __; cin >> __;
            }
        }
        sort(a.rbegin(), a.rend());
        int ans = 0;
        for (int x : a) {
            for (int b = 20; b >= 0; --b) {
                int b1 = x >> b & 1;
                int b2 = ans >> b & 1;
                if (!b1) { continue; }
                if (!b2) { ans |= (1 << b); }
                else { ans |= (1 << b) - 1; break; }
            }
        }
        cout << ans << "\n";
    }
}
