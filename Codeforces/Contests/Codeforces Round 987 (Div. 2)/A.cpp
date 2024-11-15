/**
 *    author:  MaGnsi0
 *    created: 15.11.2024 14:36:30
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
            int x; cin >> x; a[x - 1]++;
        }
        int ans = n;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, n - a[i]);
        }
        cout << ans << "\n";
    }
}
