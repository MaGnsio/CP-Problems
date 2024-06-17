/**
 *    author:  MaGnsi0
 *    created: 17.06.2024 16:03:38
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
        int ans = 0;
        for (int i = 0; i + 1 < n; ++i) {
            ans = max(ans, a[i] + a[n - 1]);
        }
        cout << ans << "\n";
    }
}
