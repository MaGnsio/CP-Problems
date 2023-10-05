/**
 *    author:  MaGnsi0
 *    created: 31.08.2023 18:38:24
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> b(n), c(n);
        for (int i = 1; i < n; ++i) {
            b[i] = a[i] >= a[i - 1];
            c[i] = a[i] <= a[i - 1];
            b[i] += b[i - 1];
            c[i] += c[i - 1];
        }
        int ans = c[n - 1];
        for (int i = 0; i < n; ++i) {
            int x = b[i];
            int y = (i < n - 1 ? c[n - 1] - c[i + 1] : 0);
            ans = min(ans, x + y + 1);
        }
        cout << ans << "\n";
    }
}
