/**
 *    author:  MaGnsi0
 *    created: 07.10.2023 20:03:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        double low = a[0] + 1.0 * (a[1] - a[0]) / 2;
        double high = a[n - 1] - 1.0 * (a[n - 1] - a[n - 2]) / 2;
        double ans = high - low;
        if (n == 5) {
            low = a[0] + 1.0 * (a[2] - a[0]) / 2;
            high = a[n - 1] - 1.0 * (a[n - 1] - a[n - 2]) / 2;
            ans = high - low;
            low = a[0] + 1.0 * (a[1] - a[0]) / 2;
            high = a[n - 1] - 1.0 * (a[n - 1] - a[n - 3]) / 2;
            ans = max(ans, high - low);
        }
        cout << "Case #" << t << ": ";
        cout << fixed << ans << "\n";
    }
}
