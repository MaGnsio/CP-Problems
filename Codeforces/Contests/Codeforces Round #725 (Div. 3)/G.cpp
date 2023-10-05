/**
 *    author:  MaGnsi0
 *    created: 10/06/2021 16:24:02
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if (a == b) {
            cout << min(x, y) / a << "\n";
            continue;
        }
        if (a < b) {
            swap(a, b);
        }
        int l = 0, r = 1e9, ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            int high = floorl((x - mid * b) * 1.0l / (a - b));
            int low = ceill((y - mid * a) * 1.0l / (b - a));
            if (max(0LL, low) <= min(high, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << ans << "\n";
    }
}
