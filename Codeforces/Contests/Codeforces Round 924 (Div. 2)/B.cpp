/**
 *    author:  MaGnsi0
 *    created: 26.09.2024 19:10:41
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
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        int m = (int)a.size();
        int ans = 0;
        for (int i = 0, j = 0; i < m; ++i) {
            while (a[i] - a[j] >= n) { j++; }
            ans = max(ans, i - j + 1);
        }
        cout << ans << "\n";
    }
}
