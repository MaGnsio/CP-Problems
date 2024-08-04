/**
 *    author:  MaGnsi0
 *    created: 04.08.2024 15:07:15
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
        if (is_sorted(a.begin(), a.end())) {
            cout << 0 << "\n";
            continue;
        }
        if (a[0] == n - 1 && a[n - 1] == 0) {
            cout << 3 << "\n";
            continue;
        }
        int ans = 2, maxa = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] == i && maxa < a[i]) {
                ans = 1;
            }
            maxa = max(maxa, a[i]);
        }
        cout << ans << "\n";
    }
}
