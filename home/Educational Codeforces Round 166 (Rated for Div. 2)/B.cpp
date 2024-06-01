/**
 *    author:  MaGnsi0
 *    created: 30.05.2024 17:40:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> a(n), b(n + 1);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i <= n; ++i) {
            cin >> b[i];
        }
        int64_t ans = 0, lastb = INT64_MAX;
        for (int i = 0; i < n; ++i) {
            if (a[i] < b[i]) {
                ans += b[i] - a[i];
                if (a[i] <= b[n] && b[n] <= b[i]) {
                    lastb = min(lastb, 1LL);
                }
            } else if (a[i] > b[i]) {
                ans += a[i] - b[i];
                if (b[i] <= b[n] && b[n] <= a[i]) {
                    lastb = min(lastb, 1LL);
                }
            }
            lastb = min(lastb, abs(b[n] - a[i]) + 1);
            lastb = min(lastb, abs(b[n] - b[i]) + 1);
        }
        cout << ans + lastb << "\n";
    }
}
