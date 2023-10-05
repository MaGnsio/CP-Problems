/**
 *    author:  MaGnsi0
 *    created: 25.02.2023 16:31:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int64_t> b(n + m + 1, 0);
        for (int i = 0; i < n; ++i) {
            b[a[i]] = m + 1;
        }
        for (int i = 0; i < m; ++i) {
            int j, x;
            cin >> j >> x;
            b[a[j - 1]] -= (m - i);
            a[j - 1] = x;
            b[a[j - 1]] += (m - i);
        }
        int64_t ans = 0;
        for (int i = 0; i <= n + m; ++i) {
            ans += b[i] * (b[i] - 1) / 2;
            ans += b[i] * (m - b[i] + 1);
        }
        cout << ans << "\n";
    }
}
