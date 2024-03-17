/**
 *    author:  MaGnsi0
 *    created: 20.01.2024 22:06:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int x; cin >> x;
        int y; cin >> y;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        for (int i = 1; i < n; ++i) {
            a[i] += a[i - 1];
        }
        int ans = a[n - 1] - 2 * a[y - 1];
        for (int i = 0; i < x; ++i) {
            int j = min(n - 1, i + y);
            ans = max(ans, a[n - 1] - a[i] - 2 * (a[j] - a[i]));
        }
        cout << ans << "\n";
    }
}
