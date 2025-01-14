/**
 *    author:  MaGnsi0
 *    created: 14.01.2025 18:52:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int ans = 0;
        for (int m = 0; m <= n; ++m) {
            int val = 1e9;
            for (int i = 0; i < n; ++i) {
                val = min(val, abs(a[i] - b[i]));
            }
            ans = max(ans, val);
            int x = a[0];
            a.erase(a.begin());
            a.push_back(x);
        }
        cout << ans << "\n";
    }
}
