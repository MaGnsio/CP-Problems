/**
 *    author:  MaGnsi0
 *    created: 13.04.2024 02:10:26
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
        for (int i = 0, sz = 0; i < n; ++i) {
            if (i == n - 1) { ans = min(ans, sz + 1); }
            if (a[i] == a[0]) { sz++; continue; }
            ans = min(ans, sz);
            sz = 0;
        }
        cout << (ans == n ? -1 : ans) << "\n";
    }
}
