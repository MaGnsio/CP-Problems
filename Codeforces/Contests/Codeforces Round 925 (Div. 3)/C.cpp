/**
 *    author:  MaGnsi0
 *    created: 13.02.2024 16:55:29
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
        int ans = n;
        for (int _ = 0; _ < 2; _++) {
            int L = 0, R = n - 1;
            while (L < n && a[L] == a[0]) { L++; }
            while (R >= 0 && a[R] == a[0]) { R--; }
            ans = min(ans, max(0, R - L + 1));
            reverse(a.begin(), a.end());
        }
        cout << ans << "\n";
    }
}
