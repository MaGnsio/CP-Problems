/**
 *    author:  MaGnsi0
 *    created: 09.02.2025 16:56:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        int k; cin >> k;
        swap(n, m);
        if (abs(n - m) > k || max(n, m) < k) {
            cout << -1 << "\n";
            continue;
        } else if (n > m) {
            string ans = "";
            for (int i = 0; i < k; ++i) {
                ans += "1"; n--;
            }
            while (n && m) {
                ans += "01"; n--; m--;
            }
            while (n--) { ans += "1"; }
            while (m--) { ans += "0"; }
            cout << ans << "\n";
        } else {
            string ans = "";
            for (int i = 0; i < k; ++i) {
                ans += "0"; m--;
            }
            while (n && m) {
                ans += "10"; n--; m--;
            }
            while (n--) { ans += "1"; }
            while (m--) { ans += "0"; }
            cout << ans << "\n";
        }
    }
}
