/**
 *    author:  MaGnsi0
 *    created: 18.10.2025 19:57:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            ans = max(ans, abs(a[i] - a[i - 1]));
        }
        cout << ans << "\n";
    }
}
