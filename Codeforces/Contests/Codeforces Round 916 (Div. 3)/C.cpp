/**
 *    author:  MaGnsi0
 *    created: 21.12.2023 15:25:42
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        for (int i = 1; i < n; ++i) {
            a[i] += a[i - 1];
        }
        for (int i = 1; i < n; ++i) {
            b[i] = max(b[i], b[i - 1]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (k < i + 1) { break; }
            ans = max(ans, (k - i - 1) * b[i] + a[i]);
        }
        cout << ans << "\n";
    }
}
