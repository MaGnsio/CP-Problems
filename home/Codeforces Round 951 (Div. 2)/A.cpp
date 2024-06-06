/**
 *    author:  MaGnsi0
 *    created: 06.06.2024 17:38:02
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
        int ans = INT_MAX;
        for (int i = 0; i + 1 < n; ++i) {
            ans = min(ans, max(a[i], a[i + 1]) - 1);
        }
        cout << ans << "\n";
    }
}
