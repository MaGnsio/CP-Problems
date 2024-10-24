/**
 *    author:  MaGnsi0
 *    created: 24.10.2024 18:15:28
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
            cin >> a[i]; a[i]--;
        }
        int ans = 0;
        vector<bool> done(n, false);
        for (int i = 0; i < n; ++i) {
            if (done[i]) { continue; }
            int m = 0;
            for (int v = i; !done[v]; v = a[v]) { done[v] = true; m++; }
            ans += (m - 1) / 2;
        }
        cout << ans << "\n";
    }
}
