/**
 *    author:  MaGnsi0
 *    created: 07.01.2024 16:54:51
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
        if (!is_sorted(a.begin(), a.end())) {
            cout << 0 << "\n";
            continue;
        }
        int ans = INT_MAX;
        for (int i = 1; i < n; ++i) {
            ans = min(ans, (a[i] - a[i - 1] + 2) / 2);
        }
        cout << ans << "\n";
    }
}
