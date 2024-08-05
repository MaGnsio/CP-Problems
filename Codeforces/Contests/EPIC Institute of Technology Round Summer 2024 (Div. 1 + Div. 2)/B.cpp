/**
 *    author:  MaGnsi0
 *    created: 30.06.2024 17:38:37
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
        vector<int64_t> b(n);
        for (int i = 1; i < n; ++i) {
            b[i] = max(a[i - 1] - a[i], 0LL);
            a[i] += b[i];
        }
        sort(b.begin(), b.end());
        int64_t ans = 0, minus = 0;
        for (int i = 0; i < n; ++i) {
            b[i] -= minus;
            if (b[i] == 0) { continue; }
            ans += b[i] * (n - i + 1);
            minus += b[i];
        }
        cout << ans << "\n";
    }
}
