/**
 *    author:  MaGnsi0
 *    created: 30.04.2024 17:36:07
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        int ans = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            if (a[j] > b[i]) {
                ans++;
            } else {
                j++;
            }
        }
        cout << ans << "\n";
    }
}
