/**
 *    author:  MaGnsi0
 *    created: 24.11.2023 22:30:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int64_t ans = a[0] - 1;
        for (int i = 1; i < n; ++i) {
            ans += max(a[i] - a[i - 1], int64_t(0));
        }
        cout << ans << "\n";
    }
}
