/**
 *    author:  MaGnsi0
 *    created: 25.01.2026 16:53:46
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
        sort(a.begin(), a.end());
        for (int i = 1; i < n; ++i) {
            b[i] += b[i - 1];
        }
        function<int64_t(int, int)> score = [&](int x, int c) {
            int l = int(upper_bound(b.begin(), b.end(), c) - b.begin());
            return int64_t(l) * x;
        };
        int64_t ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, score(a[i], n - i));
        }
        cout << ans << "\n";
    }
}
