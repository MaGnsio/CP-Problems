/**
 *    author:  MaGnsi0
 *    created: 24.11.2023 16:35:58
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int x; cin >> x;
        vector<int> a(n + 2);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        a[n + 1] = x;
        int ans = 0;
        for (int i = 1; i < n + 1; ++i) {
            ans = max(ans, a[i] - a[i - 1]);
        }
        ans = max(ans, 2 * (a[n + 1] - a[n]));
        cout << ans << "\n";
    }
}
