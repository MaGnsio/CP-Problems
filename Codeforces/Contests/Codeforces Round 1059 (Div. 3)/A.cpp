/**
 *    author:  MaGnsi0
 *    created: 17.10.2025 17:37:08
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i]; a[i] += a[i - 1];
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                int m = j - i + 1;
                int x = a[j] - a[i - 1];
                if (x % m) { continue; }
                ans = max(ans, x / m);
            }
        }
        cout << ans << "\n";
    }
}
