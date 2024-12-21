/**
 *    author:  MaGnsi0
 *    created: 21.12.2024 20:13:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; a[i] -= (i + 1);
        }
        int64_t ans = 1;
        for (int i = 0; i < k; ++i) {
            ans += lower_bound(a.begin(), a.end(), ans) - a.begin();
        }
        cout << ans << "\n";
    }
}
