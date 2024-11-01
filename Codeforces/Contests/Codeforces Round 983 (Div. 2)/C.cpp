/**
 *    author:  MaGnsi0
 *    created: 01.11.2024 16:57:36
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
        int ans = n - 2;
        for (int i = 0; i + 2 < n; ++i) {
            int j = lower_bound(a.begin(), a.end(), a[i] + a[i + 1]) - a.begin() - 1;
            ans = min(ans, n + i - j - 1);
        }
        cout << ans << "\n";
    }
}
