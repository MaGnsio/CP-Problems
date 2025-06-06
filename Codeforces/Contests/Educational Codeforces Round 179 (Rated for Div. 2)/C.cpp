/**
 *    author:  MaGnsi0
 *    created: 06.06.2025 21:28:32
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
        int64_t ans = *min_element(a.begin(), a.end()) * (n - 1);
        for (int i = 1, x = 1; i < n; ++i) {
            if (a[i] == a[i - 1]) { x++; }
            else { x = 1; }
            ans = min(ans, a[i] * (n - x));
        }
        cout << ans << "\n";
    }
}
