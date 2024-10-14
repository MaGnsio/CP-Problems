/**
 *    author:  MaGnsi0
 *    created: 14.10.2024 17:50:12
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < i && (a[i] - a[j] >= k || a[j + 1] - a[j] > 1)) { j++; }
            ans = max(ans, i - j + 1);
            if (i + 1 < n && a[i + 1] - a[i] > 1) { j = i; }
        }
        cout << ans << "\n";
    }
}
