/**
 *    author:  MaGnsi0
 *    created: 09.11.2024 23:30:55
**/
#include <bits/stdc++.h>

using namespace std;

int e(int r, int p) {
    if (r == p) { return 0; }
    return (r < p ? +1 : -1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        function<bool(int)> F = [&](int x) {
            vector<int> l(n), r(n);
            for (int i = 0; i < n; ++i) {
                l[i] = (i ? l[i - 1] : 0) + e(i ? l[i - 1] : 0, a[i]);
                int s = e(i ? r[n - i] : x, a[n - i - 1]);
                r[n - i - 1] = (i ? r[n - i] : x) - (s ? s : 1);
            }
            for (int i = 0; i < n - 1; ++i) {
                if (l[i] >= x) { return true; }
            }
            int maxr = 0;
            for (int i = 1; i < n; ++i) {
                if (r[i] <= maxr) { return true; }
                maxr = max(maxr, l[i - 1]);
            }
            return false;
        };
        int low = 0, high = n - 1, ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (F(mid)) {
                ans = mid; low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << ans << "\n";
    }
}
