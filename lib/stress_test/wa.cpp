/**
 *    author:  MaGnsi0
 *    created: 20.09.2024 18:11:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int64_t sum = 0;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        int64_t l = sum / n, r = l + (sum % n != 0);
        if (a[0] >= l && a[n - 1] <= r) {
            cout << r - l << "\n";
        } else if (a[0] >= l) {
            int64_t ans = a[n - 1] - (sum - a[n - 1]) / (n - 1);
            cout << ans << "\n";
        } else if (a[n - 1] <= r) {
            int64_t ans = (sum - a[0] + n - 2) / (n - 1) - a[0];
            cout << ans << "\n";
        } else {
            if (n == 2) {
                cout << a[n - 1] - a[0] << "\n";
                continue;
            }
            sum = sum - a[n - 1] - a[0];
            l = min(a[0], sum / (n - 2));
            r = max(a[n - 1], (sum + n - 3) / (n - 2));
            cout << r - l << "\n";
        }
    }
}
